#include "Block.h"

#include "../item/ItemStack.h"

BlockRenderLayer Block::getRenderLayer() const {
    return mLegacyBlock->getRenderLayer();
}
bool Block::isSolid() const {
    return mLegacyBlock->mSolid;
}
const Block& Block::getDefaultState() const {
    return mLegacyBlock->getDefaultState();
}
const Material& Block::getMaterial() const {
    return mLegacyBlock->getMaterial();
}
bool Block::canContainLiquid() const {
    return mLegacyBlock->canContainLiquid();
}
void Block::spawnResources(BlockSource& region, const BlockPos& pos, float explosionRadius, int bonusLootLevel) const {
    mLegacyBlock->spawnResources(region, pos, region.getBlock(pos), explosionRadius, bonusLootLevel);
}
void Block::spawnResources(BlockSource& region, const BlockPos& pos, const Block& block, float explosionRadius, int bonusLootLevel) const {
    mLegacyBlock->spawnResources(region, pos, block, explosionRadius, bonusLootLevel);
}
bool Block::hasProperty(BlockProperty type) const {
    return mLegacyBlock->hasProperty(type);
}
ItemInstance Block::asItemInstance(BlockSource& region, const BlockPos& pos) const {
    return mLegacyBlock->asItemInstance(region, pos, *this);
}
ItemInstance Block::getSilkTouchItemInstance() const {
    return mLegacyBlock->getSilkTouchItemInstance(*this);
}
void Block::playerDestroy(Player& player, const BlockPos& pos) const {
    return mLegacyBlock->playerDestroy(player, pos, *this);
}

const AABB& Block::getVisualShape(AABB& aabb, bool isClipping) const {
    return mLegacyBlock->getVisualShape(*this, aabb, isClipping);
}

int Block::getColor(BlockSource& region, const BlockPos& pos) const {
	return mLegacyBlock->getColor(region, pos, *this);
}

int Block::getColorAtPos(BlockSource& region, const BlockPos& pos) const {
    return mLegacyBlock->getColorAtPos(region, pos);
}

BlockRenderLayer Block::getRenderLayer(BlockSource& region, const BlockPos& pos) const {
    return mLegacyBlock->getRenderLayer(*this, region, pos);
}
