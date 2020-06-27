#pragma once

#include "LiquidBlock.h"

class LiquidBlockDynamic : public LiquidBlock {
public:
    LiquidBlockDynamic(const std::string&, int, const Material&);
    virtual void tick(BlockSource&, const BlockPos&, Random&) const;
    virtual void onPlace(BlockSource&, const BlockPos&) const;
    virtual void _setStatic(BlockSource&, const BlockPos&, bool) const {}
private:
    bool _tick(BlockSource&, const BlockPos&, Random&, bool) const;
};