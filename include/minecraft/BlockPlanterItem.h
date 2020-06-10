#pragma once

#include "Item.h"

class BlockPlanterItem : public Item {
private:
    const Block& mBlock;

public:
    BlockPlanterItem(const std::string&, int, const Block&, bool);
    virtual ~BlockPlanterItem();
private:
    virtual bool _useOn(ItemStack&, Actor&, BlockPos, FacingID, float, float, float) const;
    virtual bool _calculatePlacePos(ItemStack&, Actor&, FacingID&, BlockPos&) const;
};