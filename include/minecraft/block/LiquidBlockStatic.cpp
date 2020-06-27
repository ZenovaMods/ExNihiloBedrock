#include "LiquidBlockStatic.h"

#include "../world/BlockSource.h"
#include "Block.h"

LiquidBlockStatic::LiquidBlockStatic(const std::string& nameId, int id, const Material& material) : LiquidBlock(nameId, id, material) {
    setRandomTicking(material.isType(MaterialType::Lava));
}

void LiquidBlockStatic::neighborChanged(BlockSource& region, const BlockPos& pos, const BlockPos& neighborPos) const {
    LiquidBlock::neighborChanged(region, pos, neighborPos);
    if (*this == region.getLiquidBlock(pos).getLegacyBlock())
        _setDynamic(region, pos);
}