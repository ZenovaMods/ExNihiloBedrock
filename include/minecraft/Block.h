#pragma once

#include "BlockLegacy.h"
#include "SharedPtr.h"

typedef unsigned short DataID;
class ItemState;
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