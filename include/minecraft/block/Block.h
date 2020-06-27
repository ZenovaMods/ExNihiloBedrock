#pragma once

#include "BlockLegacy.h"
#include "../util/SharedPtr.h"

class Block {
private:
    const DataID mData;
    WeakPtr<BlockLegacy> mLegacyBlock;

public:
    virtual ~Block();

    const BlockLegacy& getLegacyBlock() const;

    const Block& getDefaultState() const {
        return mLegacyBlock->getDefaultState();
    }

    const DataID& getDataDEPRECATED() const {
        return mData;
    }

    template<typename T>
    T getState(const ItemState& stateType) const {
        return mLegacyBlock->getState<T>(stateType, mData);
    }

    template<typename T>
    const Block* setState(const ItemState& stateType, T val) const {
        return mLegacyBlock->setState<T>(stateType, val, mData);
    }
};