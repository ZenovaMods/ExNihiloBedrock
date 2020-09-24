#pragma once

#include <algorithm>
#include <limits>

#include "Item.h"
#include "ItemRegistry.h"

class ItemDescriptor {
private:
    WeakPtr<Item> mItem;
    const Block* mBlock = nullptr;
    short mAuxValue = 0;
    bool mValid = false;

public:
    ItemDescriptor() = default;
    ItemDescriptor(const Block& block) {
        mItem = ItemRegistry::getItem(block);
        mBlock = &block;
        mAuxValue = 0;
        mValid = mItem.get() != nullptr;
        if (!mValid) {
            mItem.reset();
            mAuxValue = 0;
            mBlock = nullptr;
        }
    }
    ItemDescriptor(const BlockLegacy& block) {
        mAuxValue = 0x7FFF;
        mItem = ItemRegistry::getItem(block);
        mBlock = &block.getDefaultState();
        mValid = mItem.get() != nullptr;
        if (!mValid) {
            mItem.reset();
            mAuxValue = 0;
            mBlock = nullptr;
        }
    }
    ItemDescriptor(const Item& item, int auxValue) : ItemDescriptor(item.getId(), auxValue) {}
private:
    ItemDescriptor(int id, int auxValue) {
        mItem = ItemRegistry::getItem(id);
        mBlock = nullptr;
        setAuxValue(auxValue);
        mValid = !mItem.get() ? id == 0 : true;
        if (!mValid) {
            mItem.reset();
            mAuxValue = 0;
            mBlock = nullptr;
        }
    }
public:

    short getAuxValue() const {
        if (mBlock != NULL && mAuxValue != 0x7FFF)
            return mBlock->getDataDEPRECATED();
        else
            return mAuxValue;
    }

    void setAuxValue(short auxValue) {
        mAuxValue = std::clamp<short>(auxValue, 0, std::numeric_limits<short>::max());
    }
};