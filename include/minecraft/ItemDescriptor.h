#pragma once

#include "Item.h"
#include "Block.h"

class ItemDescriptor {
private:
    WeakPtr<Item> mItem;
    const Block* mBlock;
    short mAuxValue;
    bool mValid;

public:
    ItemDescriptor() = default;

    short getAuxValue() const {
        if (mBlock != NULL && mAuxValue != 0x7FFF)
            return mBlock->getDataDEPRECATED();
        else
            return mAuxValue;
    }
};