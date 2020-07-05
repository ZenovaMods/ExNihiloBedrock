#include "UniversalBucket.h"

#include <sstream>

#include "minecraft/actor/Actor.h"
#include "minecraft/block/BlockTypeRegistry.h"
#include "minecraft/block/DispenserBlock.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"
#include "minecraft/item/ItemDescriptor.h"
#include "minecraft/item/ItemHelper.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/item/VanillaItems.h"
#include "minecraft/util/Facing.h"
#include "minecraft/util/I18n.h"
#include "minecraft/world/ActorEventCoordinator.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/Level.h"

#include "../blocks/FluidRegistry.h"
#include "ENItems.h"

UniversalBucket::UniversalBucket(const std::string& nameId, int id) : Item(nameId, id), mBucketTextures() {
	setMaxStackSize(1);
}

bool UniversalBucket::isValidAuxValue(int auxValue) const {
	return auxValue >= 0 && auxValue < FluidRegistry::mFluids.size();
}

std::string UniversalBucket::buildDescriptionId(const ItemDescriptor& itemDescriptor, const std::unique_ptr<CompoundTag>& userData) const {
	std::string bucketName = I18n::get(Item::buildDescriptionId(itemDescriptor, userData));
	std::string liquidName = I18n::get(FluidRegistry::mFluids[itemDescriptor.getAuxValue()]->getUnlocalizedName());
	return liquidName + " " + bucketName;
}

const TextureUVCoordinateSet& UniversalBucket::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	if (FluidRegistry::mFluids.size() > 0)
		return mBucketTextures[itemStack.getAuxValue()];
	return Item::getIcon(itemStack, frame, isInventoryPane);
}

Item& UniversalBucket::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	mBucketTextures.reserve(FluidRegistry::mFluids.size());
	for (Fluid* fluid : FluidRegistry::mFluids) {
		mBucketTextures.push_back(getTextureUVCoordinateSet(fluid->mBucketTextureItem, fluid->mBucketTextureIndex));
	}
	return *this;
}

std::string UniversalBucket::getAuxValuesDescription() const {
	std::stringstream ret;
	for (Fluid* fluid : FluidRegistry::mFluids) {
		ret << std::endl << fluid->mId << " = " << I18n::get(fluid->getUnlocalizedName());
	}
	return ret.str();
}

bool UniversalBucket::dispense(BlockSource& region, Container& container, int slot, const Vec3& pos, FacingID face) const {
	const ItemStack& itemStack = container.getItem(slot);
	BlockLegacy* contentsBlock = FluidRegistry::mFluids[itemStack.getAuxValue()]->mFlowingBlock->get();
	if (contentsBlock) {
		if (_emptyBucket(region, contentsBlock->getDefaultState(), pos, nullptr, itemStack, face)) {
			region.getLevel().broadcastLevelEvent(LevelEvent::SoundClick, pos, 1000, nullptr);
			container.removeItem(slot, 1);
			ItemStack emptyBucket(**VanillaItems::mBucket, 1, 0);
			if (!container.addItemToFirstEmptySlot(emptyBucket))
				DispenserBlock::ejectItem(region, pos, face, emptyBucket);
			return true;
		}
	}
	return false;
}

bool UniversalBucket::dispenseEmpty(BlockSource& region, Container& container, int slot, const Vec3& pos, FacingID face) {
	Zenova::Platform::DebugPause();
	const BlockLegacy& dispensedBlock = region.getLiquidBlock(pos).getLegacyBlock();
	Fluid* fluid = FluidRegistry::getFluidFromBlock(dispensedBlock);
	if (fluid && !container.getItem(slot).getAuxValue() && !region.getLiquidBlock(pos).getState<int>(*VanillaStates::LiquidDepth)) {
		if (dispensedBlock != region.getBlock(pos).getLegacyBlock())
			region.setExtraBlock(pos, BedrockBlockTypes::mAir->get()->getDefaultState(), 3);
		else
			region.removeBlock(pos);
		region.getLevel().broadcastLevelEvent(LevelEvent::SoundClick, pos, 1000, nullptr);
		container.removeItem(slot, 1);
		ItemStack filledBucket(*ENItems::universalBucket, 1, fluid->mId);
		if (!container.addItemToFirstEmptySlot(filledBucket))
			DispenserBlock::ejectItem(region, pos, face, filledBucket);
		return true;
	}
	return false;
}

bool UniversalBucket::_useOn(ItemStack& instance, Actor& entity, BlockPos pos, FacingID face, float clickX, float clickY, float clickZ) const {
	BlockSource& region = entity.getRegion();
	BlockPos placePos = pos;
	BlockLegacy* contentsBlock = FluidRegistry::mFluids[instance.getAuxValue()]->mFlowingBlock->get();
	if (contentsBlock) {
		if (!region.getBlock(pos).canContainLiquid()) {
			placePos = placePos.neighbor(face);
		}
		const Block& blockTest = region.getBlock(placePos.below());
		if (blockTest.getLegacyBlock() == **VanillaBlockTypes::mTopSnow) {
			region.getLevel().broadcastDimensionEvent(region, LevelEvent::ParticlesDestroyBlock, placePos.below(), blockTest, nullptr);
			region.removeBlock(placePos.below());
			placePos = placePos.below();
		}
		if (_emptyBucket(region, contentsBlock->getDefaultState(), placePos, &entity, instance, face)) {
			ItemStack emptyBucket(**VanillaItems::mBucket, 1, 0);
			region.getLevel().broadcastSoundEvent(region, LevelSoundEvent::BucketEmptyWater, entity.getAttachPos(ActorLocation::Feet, 0.0F), -1, {}, false, false);
			entity.useItem(instance, ItemUseMethod::PourBucket, true);
			if (entity.hasType(ActorType::Player) && (!entity.isCreative() || instance.hasUserData())) {
				entity.getLevel().getActorEventCoordinator().sendActorAcquiredItem(entity, emptyBucket, emptyBucket.getStackSize(), ItemAcquisitionMethod::Filled, nullptr);
				if (instance.isEmptyStack() || instance.hasUserData())
					instance = emptyBucket;
				else
					entity.add(emptyBucket);
			}
			return true;
		}
	}
	return false;
}

bool UniversalBucket::_emptyBucket(BlockSource& region, const Block& contents, const BlockPos& pos, Actor* placer, const ItemStack& instance, FacingID face) const {
	const Block& oldBlock = region.getBlock(pos);
	const Block& extraBlock = region.getExtraBlock(pos);
	if (_canEmptyBucketIntoBlock(oldBlock, extraBlock) || (placer == nullptr && oldBlock.getMaterial().getType() == MaterialType::Portal)) {
		BlockPos behindPos = pos + (pos - pos.neighbor(face));
		if (placer == nullptr || region.checkBlockPermissions(*placer, behindPos, face, instance, false)) {
			if (oldBlock.canContainLiquid() && oldBlock.getLegacyBlock() != **BedrockBlockTypes::mAir) {
				region.setExtraBlock(pos, contents, 3);
			}
			else {
				if (oldBlock.getLegacyBlock().waterSpreadCausesSpawn())
					oldBlock.spawnResources(region, pos, 1.0F, 0);
				if (oldBlock.getLegacyBlock() == **BedrockBlockTypes::mAir || !oldBlock.getMaterial().isSolid())
					region.setBlock(pos, contents, 3, nullptr);
			}
			return true;
		}
	}
	return false;
}

bool UniversalBucket::_canEmptyBucketIntoBlock(const Block& block, const Block& extraBlock) const {
	if (!block.getMaterial().isSolid() || block.canContainLiquid()) {
		if (block.getMaterial().getType() != MaterialType::Portal) {
			if (extraBlock.getLegacyBlock() == **BedrockBlockTypes::mAir)
				return true;
		}
	}
	return false;
}

bool UniversalBucket::_takeLiquid(ItemStack& itemStack, Actor& entity, const BlockPos& pos) {
	BlockSource& region = entity.getRegion();
	const Block& oldBlock = region.getLiquidBlock(pos);
	Fluid* fluid = FluidRegistry::getFluidFromBlock(oldBlock.getLegacyBlock());
	if (fluid && !oldBlock.getState<int>(*VanillaStates::LiquidDepth)) {
		const Block& aboveLiquidBlock = region.getLiquidBlock(pos.above());
		const Block& aboveBlock = region.getBlock(pos.above());
		bool shouldRemoveLiquid = true;
		if (aboveBlock.isSolid() || !aboveLiquidBlock.getState<int>(*VanillaStates::LiquidDepth)) {
			shouldRemoveLiquid = false;
			for (auto& it : Facing::ALL_EXCEPT[1]) {
				const Block& block = region.getLiquidBlock(pos.neighbor(it));
				if (!block.isSolid() && block.getState<int>(*VanillaStates::LiquidDepth)) {
					shouldRemoveLiquid = true;
					break;
				}
			}
		}
		if (shouldRemoveLiquid) {
			bool isUsingExtraData = region.getExtraBlock(pos).getLegacyBlock() != **BedrockBlockTypes::mAir;
			region.setLiquidBlock(pos, BedrockBlockTypes::mAir->get()->getDefaultState(), isUsingExtraData, 3);
		}
		entity.getLevel().broadcastSoundEvent(region, LevelSoundEvent::BucketFillWater, entity.getAttachPos(ActorLocation::Feet, 0.0F), -1, {}, 0, 0);
		ItemStack filledBucket(*ENItems::universalBucket, 1, fluid->mId);
		entity.getLevel().getActorEventCoordinator().sendActorUseItem(entity, itemStack, ItemUseMethod::FillBucket);
		if (!entity.isCreative() && entity.hasType(ActorType::Player))
		{
			itemStack.remove(1);
			itemStack.getItem()->_helpChangeInventoryItemInPlace(entity, itemStack, filledBucket, ItemAcquisitionMethod::Filled);
		}
		return true;
	}
	return false;
}