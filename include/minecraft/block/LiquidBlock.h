#pragma once

#include <algorithm>

#include "BlockLegacy.h"

class LiquidBlock : public BlockLegacy {
public:
    LiquidBlock(const std::string&, int, const Material&);
    virtual bool canContainLiquid() const;
    virtual bool mayPick(BlockSource&, const Block&, bool) const;
    virtual const AABB& getAABB(BlockSource&, const BlockPos&, const Block&, AABB&, bool) const;
    virtual int getResourceCount(Random&, const Block&, int) const;
    virtual int getColor(const Block&) const;
    virtual int getColorAtPos(BlockSource&, const BlockPos&) const;
    virtual Color getMapColor(BlockSource&, const BlockPos&) const;
    virtual void handleEntityInside(BlockSource&, const BlockPos&, Actor*, Vec3&) const;
    virtual void animateTick(BlockSource&, const BlockPos&, Random&) const;
    virtual void onPlace(BlockSource&, const BlockPos&) const;
    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual bool checkIsPathable(Actor&, const BlockPos&, const BlockPos&) const;
    virtual bool canBeSilkTouched() const;

    int getTickDelay(BlockSource&) const;
};