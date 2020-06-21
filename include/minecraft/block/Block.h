#pragma once

#include "BlockLegacy.h"
#include "../util/SharedPtr.h"

enum class SaplingType;

class Block {
private:
    const DataID mData;
    WeakPtr<BlockLegacy> mLegacyBlock;

public:
    virtual ~Block();

    const BlockLegacy& getLegacyBlock() const;

    const DataID& getDataDEPRECATED() const {
        return mData;
    }

    const Block* getSaplingType(const ItemState&, SaplingType) const;
};