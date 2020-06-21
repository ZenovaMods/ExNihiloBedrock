#pragma once

#include "LiquidBlock.h"

class LiquidBlockStatic : public LiquidBlock {
public:
    LiquidBlockStatic(const std::string& nameId, int id, const Material& material) : LiquidBlock(nameId, id, material) {
        setRandomTicking(material.isType(MaterialType::Lava));
    }
    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual void tick(BlockSource&, const BlockPos&, Random&) const;
};