#include "BlockFluidWitchWaterStill.h"

#include "ENBlocks.h"

#include "minecraft/block/Block.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/world/BlockSource.h"

BlockFluidWitchWaterStill::BlockFluidWitchWaterStill(const std::string& nameId, int id) : LiquidBlockStatic(nameId, id, Material::getMaterial(MaterialType::Water)) {
}

Color BlockFluidWitchWaterStill::getMapColor(BlockSource&, const BlockPos&) const {
    return { 0.125F, 0.0F, 0.322F, 1.0F };
}

void BlockFluidWitchWaterStill::_setDynamic(BlockSource& region, const BlockPos& pos) const {
    bool usingExtraData = region.getBlock(pos).getLegacyBlock() != *this;
    auto& liquidBlock = region.getLiquidBlock(pos);
    int depth = liquidBlock.getState<int>(*VanillaStates::LiquidDepth);

    if (*this == liquidBlock.getLegacyBlock()) {
        const Block* dynamicLiquid = ENBlocks::blockWitchwaterFlowing->getDefaultState().setState(*VanillaStates::LiquidDepth, depth);
        region.setLiquidBlock(pos, *dynamicLiquid, usingExtraData, 4);
        region.addToTickingQueue(pos, *dynamicLiquid, getTickDelay(region), 0);
    }
}
