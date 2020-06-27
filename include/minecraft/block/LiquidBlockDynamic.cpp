#include "LiquidBlockDynamic.h"

#include "../world/BlockSource.h"
#include "Block.h"

LiquidBlockDynamic::LiquidBlockDynamic(const std::string& nameId, int id, const Material& material) : LiquidBlock(nameId, id, material) {
}

void LiquidBlockDynamic::tick(BlockSource& region, const BlockPos& pos, Random& random) const {
	bool usingExtraData = region.getBlock(pos).getLegacyBlock() != *this;
	if (_tick(region, pos, random, false))
		_setStatic(region, pos, usingExtraData);
}

void LiquidBlockDynamic::onPlace(BlockSource& region, const BlockPos& pos) const {
	LiquidBlock::onPlace(region, pos);
	if (*this == region.getLiquidBlock(pos).getLegacyBlock())
		region.addToTickingQueue(pos, getDefaultState(), getTickDelay(region), 0);
}
