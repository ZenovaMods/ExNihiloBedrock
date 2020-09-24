#include "BlockInfestedLeaves.h"

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
#include "../blockactors/BlockActorInfestedLeaves.h"

BlockInfestedLeaves::BlockInfestedLeaves(const std::string& nameId, int id) : ActorBlock(nameId, id, Material::getMaterial(MaterialType::Leaves)) {
	setSolid(false);
	setPushesOutItems(true);
	mRenderLayer = BlockRenderLayer::RENDERLAYER_SEASONS_OPTIONAL_ALPHATEST;
	mBrightnessGamma = 0.8F;
	mBlockEntityType = BlockActorType::InfestedLeaves;
	addProperty(BlockProperty::Leaf);
	addProperty(BlockProperty::BreakOnPush);
	setDestroyTime(0.2F);
	setLightBlock(1);
	setCategory(CreativeItemCategory::DECORATIONS);
}

bool BlockInfestedLeaves::canProvideSupport(const Block&, FacingID, BlockSupportType) const {
	return false;
}

bool BlockInfestedLeaves::canContainLiquid() const {
	return true;
}

bool BlockInfestedLeaves::breaksFallingBlocks(const Block&) const {
	return false;
}

Color BlockInfestedLeaves::getMapColor(BlockSource& region, const BlockPos& pos) const {
	return Color::fromARGB(0x8A8A8A) * Color::fromARGB(0xFFFFFF);
}

BlockRenderLayer BlockInfestedLeaves::getRenderLayer(const Block& block, BlockSource& region, const BlockPos& pos) const {
	bool canHaveSnowfall = region.getBiome(pos).canHaveSnowfall(region, pos);
	if (LeafBlock::isDeepLeafBlock(region, pos))
		return (canHaveSnowfall && mHasTransparentLeaves) ? BlockRenderLayer::RENDERLAYER_SEASONS_OPAQUE : BlockRenderLayer::RENDERLAYER_OPAQUE;
	else if (canHaveSnowfall)
		return mHasTransparentLeaves ? BlockRenderLayer::RENDERLAYER_SEASONS_OPTIONAL_ALPHATEST : BlockRenderLayer::RENDERLAYER_OPAQUE;
	else
		return mHasTransparentLeaves ? BlockRenderLayer::RENDERLAYER_OPTIONAL_ALPHATEST : BlockRenderLayer::RENDERLAYER_OPAQUE;
}

bool BlockInfestedLeaves::isAuxValueRelevantForPicking() const {
	return true;
}

int BlockInfestedLeaves::getColor(BlockSource& region, const BlockPos& pos, const Block& block) const {
	return 0xFFFFFF;
}

void BlockInfestedLeaves::onGraphicsModeChanged(bool fancy, bool transparentLeaves, bool fancyBubbles) {
	mHasTransparentLeaves = transparentLeaves;
	mRenderLayer = (BlockRenderLayer)(4 * mHasTransparentLeaves + 2);
	setLightBlock(1);
	BlockLegacy::onGraphicsModeChanged(fancy, transparentLeaves, fancyBubbles);
}

int BlockInfestedLeaves::getResourceCount(Random&, const Block&, int) const {
	return 0;
}

void BlockInfestedLeaves::playerDestroy(Player& player, const BlockPos& pos, const Block& block) const {
	BlockLegacy::playerDestroy(player, pos, block);
}

std::shared_ptr<BlockActor> BlockInfestedLeaves::newBlockEntity(const BlockPos& pos) const {
	return std::make_shared<BlockActorInfestedLeaves>(pos);
}

BlockInfestedLeavesOld::BlockInfestedLeavesOld(const std::string& nameId, int id) : BlockInfestedLeaves(nameId, id) {
	addState(*VanillaStates::OldLeafType);
	addState(*VanillaStates::UpdateBit);
}

int BlockInfestedLeavesOld::getVariant(const Block& block) const {
	OldLeafType leafType = block.getState<OldLeafType>(*VanillaStates::OldLeafType);
	return enum_cast(leafType);
}

ItemInstance BlockInfestedLeavesOld::asItemInstance(BlockSource& region, const BlockPos& pos, const Block& block) const {
	return ItemInstance(block.keepState(*VanillaStates::OldLeafType), 1, nullptr);
}

ItemInstance BlockInfestedLeavesOld::getSilkTouchItemInstance(const Block& block) const {
	return ItemInstance(block.keepState(*VanillaStates::OldLeafType), 1, nullptr);
}

std::string BlockInfestedLeavesOld::buildDescriptionId(const Block& block) const {
	static const std::string LEAF_NAMES[4] = { "oak", "spruce", "birch", "jungle" };
	OldLeafType type = block.getState<OldLeafType>(*VanillaStates::OldLeafType);
	if (type < OldLeafType::Oak || type >= OldLeafType::_count)
		type = OldLeafType::Oak;
	std::string descriptionId = "tile.leaves";
	std::string infestedName = I18n::get(BlockLegacy::buildDescriptionId(block));
	std::string leafName = I18n::get(descriptionId + "." + LEAF_NAMES[enum_cast(type)] + ".name");
	return infestedName + " " + leafName;
}

BlockLegacy& BlockInfestedLeavesOld::init() {
	addLegacyDataFromPermutations();
	return BlockLegacy::init();
}

BlockInfestedLeavesNew::BlockInfestedLeavesNew(const std::string& nameId, int id) : BlockInfestedLeaves(nameId, id) {
	addState(*VanillaStates::NewLeafType);
	addState(*VanillaStates::UpdateBit);
}

int BlockInfestedLeavesNew::getVariant(const Block& block) const {
	NewLeafType leafType = block.getState<NewLeafType>(*VanillaStates::NewLeafType);
	return enum_cast(leafType);
}

ItemInstance BlockInfestedLeavesNew::asItemInstance(BlockSource& region, const BlockPos& pos, const Block& block) const {
	return ItemInstance(block.keepState(*VanillaStates::NewLeafType), 1, nullptr);
}

ItemInstance BlockInfestedLeavesNew::getSilkTouchItemInstance(const Block& block) const {
	return ItemInstance(block.keepState(*VanillaStates::NewLeafType), 1, nullptr);
}

std::string BlockInfestedLeavesNew::buildDescriptionId(const Block& block) const {
	static const std::string LEAF_NAMES[2] = { "acacia", "big_oak" };
	NewLeafType type = block.getState<NewLeafType>(*VanillaStates::NewLeafType);
	if (type < NewLeafType::Acacia || type >= NewLeafType::_count)
		type = NewLeafType::Acacia;
	std::string descriptionId = "tile.leaves2";
	std::string infestedName = I18n::get(BlockLegacy::buildDescriptionId(block));
	std::string leafName = I18n::get(descriptionId + "." + LEAF_NAMES[enum_cast(type)] + ".name");
	return infestedName + " " + leafName;
}

BlockLegacy& BlockInfestedLeavesNew::init() {
	addLegacyDataFromPermutations();
	return BlockLegacy::init();
}
