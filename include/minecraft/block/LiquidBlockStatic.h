#pragma once

#include "LiquidBlock.h"

class LiquidBlockStatic : public LiquidBlock {
public:
    LiquidBlockStatic(const std::string&, int, const Material&);

    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual void tick(BlockSource&, const BlockPos&, Random&) const {}
    virtual void _setDynamic(BlockSource&, const BlockPos&) const {}
};