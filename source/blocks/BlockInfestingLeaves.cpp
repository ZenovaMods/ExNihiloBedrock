#include "BlockInfestingLeaves.h"

#include "minecraft/actor/Player.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/LeafBlock.h"
#include "minecraft/block/LeafType.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"
#include "minecraft/blockactor/BlockActorType.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/util/I18n.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Biome.h"

#include "ENBlocks.h"
#include "../blockactors/BlockActorInfestingLeaves.h"

BlockInfestingLeaves::BlockInfestingLeaves(const std::string& nameId, int id) : ActorBlock(nameId, id, Material::getMaterial(MaterialType::Leaves)) {
	setSolid(false);
	setPushesOutItems(true);
	mRenderLayer = BlockRenderLayer::RENDERLAYER_SEASONS_OPTIONAL_ALPHATEST;
	mBrightnessGamma = 0.8F;
	mBlockEntityType = BlockActorType::InfestingLeaves;
	addProperty(BlockProperty::Leaf);
	addProperty(BlockProperty::BreakOnPush);
	addState(*VanillaStates::UpdateBit);
	setDestroyTime(0.2F);
	setLightBlock(1);
	setCategory(CreativeItemCategory::DECORATIONS);
}

bool BlockInfestingLeaves::canProvideSupport(const Block&, FacingID, BlockSupportType) const {
	return false;
}

bool BlockInfestingLeaves::canContainLiquid() const {
	return true;
}

bool BlockInfestingLeaves::breaksFallingBlocks(const Block&) const {
	return false;
}

Color BlockInfestingLeaves::getMapColor(BlockSource& region, const BlockPos& pos) const {
	const Block& block = region.getBlock(pos);
	OldLeafType type = block.hasState(*VanillaStates::OldLeafType) ? block.getState<OldLeafType>(*VanillaStates::OldLeafType) : OldLeafType::Oak;
	Color result = Color::fromARGB(0x8A8A8A);
	int totalRed = 0;
	int totalGreen = 0;
	int totalBlue = 0;
	BlockPos offset;
	for (offset.x = -1; offset.x < 2; offset.x++) {
		for (offset.z = -1; offset.z < 2; offset.z++) {
			if (offset.x || offset.z) {
				Biome& biome = region.getBiome(pos + (offset * 4));
				int foliageColor;
				if (type == OldLeafType::Spruce)
					foliageColor = biome.getMapEvergreenFoliageColor(pos);
				else if (type == OldLeafType::Birch)
					foliageColor = biome.getMapBirchFoliageColor(pos);
				else
					foliageColor = biome.getMapFoliageColor(pos);
				totalRed += get_r(foliageColor);
				totalGreen += get_g(foliageColor);
				totalBlue += get_b(foliageColor);
			}
		}
	}
	Color c = Color::fromARGB((totalBlue / 8) | ((totalGreen / 8) << 8) | ((totalRed / 8) << 16));
	Color infestColor = Color::fromARGB(0xFFFFFF);
	float progress = 1.0F;
	BlockActor* tile = region.getBlockEntity(pos);
	if (tile != nullptr && tile->isType(BlockActorType::InfestingLeaves))
		progress = dynamic_cast<BlockActorInfestingLeaves*>(tile)->getProgress();
	return result * Color::average(c, infestColor, progress);
}

int BlockInfestingLeaves::getColor(BlockSource& region, const BlockPos& pos, const Block& block) const {
	OldLeafType type = block.hasState(*VanillaStates::OldLeafType) ? block.getState<OldLeafType>(*VanillaStates::OldLeafType) : OldLeafType::Oak;
	if (isSeasonTinted(block, region, pos)) {
		if (type == OldLeafType::Spruce)
			return getSeasonsColor(region, pos, 1, 1).toARGB();
		else if (type == OldLeafType::Birch)
			return getSeasonsColor(region, pos, 2, 4).toARGB();
		return getSeasonsColor(region, pos, 5, 7).toARGB();
	}
	else {
		int totalRed = 0;
		int totalGreen = 0;
		int totalBlue = 0;
		BlockPos offset;
		for (offset.x = -1; offset.x < 2; offset.x++) {
			for (offset.z = -1; offset.z < 2; offset.z++) {
				if (offset.x || offset.z) {
					Biome& biome = region.getBiome(pos + (offset * 4));
					int foliageColor;
					if (type == OldLeafType::Spruce)
						foliageColor = biome.getEvergreenFoliageColor(pos);
					else if (type == OldLeafType::Birch)
						foliageColor = biome.getBirchFoliageColor(pos);
					else
						foliageColor = biome.getFoliageColor(pos);
					totalRed += get_r(foliageColor);
					totalGreen += get_g(foliageColor);
					totalBlue += get_b(foliageColor);
				}
			}
		}
		return (totalBlue / 8) | ((totalGreen / 8) << 8) | ((totalRed / 8) << 16);
	}
	/*Color leafColor = Color::fromARGB(getLeafColor(region, pos, block));
	Color infestColor = Color::fromARGB(0xFFFFFF);
	float progress = 1.0F;
	BlockActor* tile = region.getBlockEntity(pos);
	if (tile != nullptr && tile->isType(BlockActorType::InfestedLeaves))
		progress = dynamic_cast<BlockActorInfestedLeaves*>(tile)->getProgress();
	return Color::average(leafColor, infestColor, progress).toARGB();*/
}

BlockRenderLayer BlockInfestingLeaves::getRenderLayer(const Block& block, BlockSource& region, const BlockPos& pos) const {
	bool canHaveSnowfall = region.getBiome(pos).canHaveSnowfall(region, pos);
	if (LeafBlock::isDeepLeafBlock(region, pos))
		return (canHaveSnowfall && mHasTransparentLeaves) ? BlockRenderLayer::RENDERLAYER_SEASONS_OPAQUE : BlockRenderLayer::RENDERLAYER_OPAQUE;
	else if (canHaveSnowfall)
		return mHasTransparentLeaves ? BlockRenderLayer::RENDERLAYER_SEASONS_OPTIONAL_ALPHATEST : BlockRenderLayer::RENDERLAYER_OPAQUE;
	else
		return mHasTransparentLeaves ? BlockRenderLayer::RENDERLAYER_OPTIONAL_ALPHATEST : BlockRenderLayer::RENDERLAYER_OPAQUE;
}

bool BlockInfestingLeaves::isAuxValueRelevantForPicking() const {
	return true;
}

bool BlockInfestingLeaves::isSeasonTinted(const Block& block, BlockSource& region, const BlockPos& pos) const {
	BlockRenderLayer layer = getRenderLayer(block, region, pos);
	return mHasTransparentLeaves && (layer == BlockRenderLayer::RENDERLAYER_SEASONS_OPAQUE || layer == BlockRenderLayer::RENDERLAYER_SEASONS_OPTIONAL_ALPHATEST);
}

void BlockInfestingLeaves::onGraphicsModeChanged(bool fancy, bool transparentLeaves, bool fancyBubbles) {
	mHasTransparentLeaves = transparentLeaves;
	mRenderLayer = (BlockRenderLayer)(4 * mHasTransparentLeaves + 2);
	setLightBlock(1);
	BlockLegacy::onGraphicsModeChanged(fancy, transparentLeaves, fancyBubbles);
}

int BlockInfestingLeaves::getResourceCount(Random&, const Block&, int) const {
	return 0;
}

void BlockInfestingLeaves::playerDestroy(Player& player, const BlockPos& pos, const Block& block) const {
	const Block* leafBlock = &ENBlocks::infestedLeaves->get()->getDefaultState();
	BlockActor* tile = player.getRegion().getBlockEntity(pos);
	if (tile != nullptr && tile->isType(BlockActorType::InfestingLeaves))
		leafBlock = dynamic_cast<BlockActorInfestingLeaves*>(tile)->getLeafBlock();
	leafBlock->playerDestroy(player, pos);
}

ItemInstance BlockInfestingLeaves::asItemInstance(BlockSource& region, const BlockPos& pos, const Block& block) const {
	const Block* leafBlock = &ENBlocks::infestedLeaves->get()->getDefaultState();
	BlockActor* tile = region.getBlockEntity(pos);
	if (tile != nullptr && tile->isType(BlockActorType::InfestingLeaves))
		leafBlock = dynamic_cast<BlockActorInfestingLeaves*>(tile)->getLeafBlock();
	return leafBlock->asItemInstance(region, pos);
}

std::shared_ptr<BlockActor> BlockInfestingLeaves::newBlockEntity(const BlockPos& pos) const {
	return std::make_shared<BlockActorInfestingLeaves>(pos);
}

void BlockInfestingLeaves::infestLeafBlock(BlockSource& region, const BlockPos& pos) {
	//if (!region.getLevel().isClientSide()) {
	Zenova::Platform::DebugPause();
	const Block& block = region.getBlock(pos);
	const Block* infestedLeaf = nullptr;

	if (block.getLegacyBlock() == **VanillaBlockTypes::mLeaves) {
		Block& infestedLeafBlock = ENBlocks::infestedLeaves->get()->getDefaultState();
		OldLeafType leafType = block.getState<OldLeafType>(*VanillaStates::OldLeafType);
		infestedLeaf = infestedLeafBlock.setState<OldLeafType>(*VanillaStates::OldLeafType, leafType);
	}
	else if (block.getLegacyBlock() == **VanillaBlockTypes::mLeaves2) {
		Block& infestedLeafBlock = ENBlocks::infestedLeaves2->get()->getDefaultState();
		NewLeafType leafType = block.getState<NewLeafType>(*VanillaStates::NewLeafType);
		infestedLeaf = infestedLeafBlock.setState<NewLeafType>(*VanillaStates::NewLeafType, leafType);
	}

	region.setBlock(pos, ENBlocks::infestingLeaves->get()->getDefaultState(), 2, nullptr);
	BlockActor* tile = region.getBlockEntity(pos);
	if (infestedLeaf != nullptr && tile != nullptr && tile->isType(BlockActorType::InfestingLeaves))
		dynamic_cast<BlockActorInfestingLeaves*>(tile)->setLeafBlock(infestedLeaf);
	//}
}