#include "BlockFluidWitchWaterFlowing.h"

#include "ENBlocks.h"

#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Level.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/BlockPalette.h"

BlockFluidWitchWaterFlowing::BlockFluidWitchWaterFlowing(const std::string& nameId, int id) : LiquidBlockDynamic(nameId, id, Material::getMaterial(MaterialType::Water)) {
}

Color BlockFluidWitchWaterFlowing::getMapColor(BlockSource&, const BlockPos&) const {
	return {0.125F, 0.0F, 0.322F, 1.0F};
}

void BlockFluidWitchWaterFlowing::_setStatic(BlockSource& region, const BlockPos& pos, bool usingExtraData) const {
	auto& block = region.getLiquidBlock(pos);
	auto& palette = region.getLevel().getGlobalBlockPalette();
	if (*this == block.getLegacyBlock())
		region.setLiquidBlock(pos, palette.switchBlock(block, *ENBlocks::blockWitchwaterStill), usingExtraData, 2);
}
