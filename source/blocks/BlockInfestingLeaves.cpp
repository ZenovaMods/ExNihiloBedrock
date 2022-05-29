#include "BlockInfestingLeaves.h"

#include "minecraft/actor/Player.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/LeafBlock.h"
#include "minecraft/block/LeafType.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"
#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/blockactor/BlockActorType.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/util/I18n.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Biome.h"

#include "ENBlocks.h"
#include "../blockactors/BlockActorInfestingLeaves.h"

BlockInfestingLeaves::BlockInfestingLeaves(const std::string& nameId, int id) : BlockInfestedLeaves(nameId, id) {
	mBlockEntityType = BlockActorType::InfestingLeaves;
}

Color BlockInfestingLeaves::getMapColor(BlockSource& region, const BlockPos& pos) const {
	const Block& block = region.getBlock(pos);
	OldLeafType type = block.hasState(VanillaStates::OldLeafType) ? block.getState<OldLeafType>(VanillaStates::OldLeafType) : OldLeafType::Oak;
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
	float progress = 1.0f;
	BlockActor* tile = region.getBlockEntity(pos);
	if (tile != nullptr && tile->isType(BlockActorType::InfestingLeaves))
		progress = static_cast<BlockActorInfestingLeaves*>(tile)->getProgress();
	return result * Color::average(c, infestColor, progress);
}

int BlockInfestingLeaves::getColor(BlockSource& region, const BlockPos& pos, const Block& block) const {
	OldLeafType type = block.hasState(VanillaStates::OldLeafType) ? block.getState<OldLeafType>(VanillaStates::OldLeafType) : OldLeafType::Oak;
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
}

bool BlockInfestingLeaves::isSeasonTinted(const Block& block, BlockSource& region, const BlockPos& pos) const {
	BlockRenderLayer layer = getRenderLayer(block, region, pos);
	return mHasTransparentLeaves && (layer == BlockRenderLayer::RENDERLAYER_SEASONS_OPAQUE || layer == BlockRenderLayer::RENDERLAYER_SEASONS_OPTIONAL_ALPHATEST);
}

ItemInstance BlockInfestingLeaves::asItemInstance(BlockSource& region, const BlockPos& pos, const Block& block) const {
	return getBlockForLeaf(block, LeafType::Default).asItemInstance(region, pos);
}

ItemInstance BlockInfestingLeaves::getSilkTouchItemInstance(const Block& block) const {
	return getBlockForLeaf(block, LeafType::Default).getSilkTouchItemInstance();
}

std::shared_ptr<BlockActor> BlockInfestingLeaves::newBlockEntity(const BlockPos& pos) const {
	return std::make_shared<BlockActorInfestingLeaves>(pos);
}

float BlockInfestingLeaves::getStringDropChance(BlockActor* leaf) const {
	if (leaf != nullptr && leaf->isType(BlockActorType::InfestingLeaves))
		return static_cast<BlockActorInfestingLeaves*>(leaf)->getProgress();
	return 0.0f;
}

void BlockInfestingLeaves::infestLeafBlock(BlockSource& region, const BlockPos& pos) {
	const Block& block = region.getBlock(pos);

	if (block.getLegacyBlock() == *VanillaBlockTypes::mLeaves || block.getLegacyBlock() == *VanillaBlockTypes::mLeaves2)
		region.setBlock(pos, getBlockForLeaf(block, LeafType::Infesting), UPDATE_CLIENTS, nullptr);
}

const Block& BlockInfestingLeaves::getBlockForLeaf(const Block& leafBlock, LeafType leafType) {
	const Block& oldLeafBlock = leafType == LeafType::Default ? *VanillaBlocks::mLeaves
		: (leafType == LeafType::Infesting ? ENBlocks::infestingLeaves->get()->getDefaultState()
		: ENBlocks::infestedLeaves->get()->getDefaultState());
	const Block& newLeafBlock = leafType == LeafType::Default ? *VanillaBlocks::mLeaves2
		: (leafType == LeafType::Infesting ? ENBlocks::infestingLeaves2->get()->getDefaultState()
		: ENBlocks::infestedLeaves2->get()->getDefaultState());
	if (leafBlock.hasState(VanillaStates::OldLeafType))
		return *oldLeafBlock.setState(VanillaStates::OldLeafType, leafBlock.getState<OldLeafType>(VanillaStates::OldLeafType));
	else if (leafBlock.hasState(VanillaStates::NewLeafType))
		return *newLeafBlock.setState(VanillaStates::NewLeafType, leafBlock.getState<NewLeafType>(VanillaStates::NewLeafType));
	return oldLeafBlock;
}

BlockInfestingLeavesOld::BlockInfestingLeavesOld(const std::string& nameId, int id) : BlockInfestingLeaves(nameId, id) {
	addState(VanillaStates::OldLeafType);
	addState(VanillaStates::UpdateBit);
}

int BlockInfestingLeavesOld::getVariant(const Block& block) const {
	OldLeafType leafType = block.getState<OldLeafType>(VanillaStates::OldLeafType);
	return Zenova::enum_cast(leafType);
}

BlockLegacy& BlockInfestingLeavesOld::init() {
	addLegacyDataFromPermutations();
	return BlockLegacy::init();
}

BlockInfestingLeavesNew::BlockInfestingLeavesNew(const std::string& nameId, int id) : BlockInfestingLeaves(nameId, id) {
	addState(VanillaStates::NewLeafType);
	addState(VanillaStates::UpdateBit);
}

int BlockInfestingLeavesNew::getVariant(const Block& block) const {
	NewLeafType leafType = block.getState<NewLeafType>(VanillaStates::NewLeafType);
	return Zenova::enum_cast(leafType);
}

BlockLegacy& BlockInfestingLeavesNew::init() {
	addLegacyDataFromPermutations();
	return BlockLegacy::init();
}