#pragma once

#include "BlockLegacy.h"
#include "SharedPtr.h"

typedef unsigned short DataID;

class Block {
private:
    const DataID mData;
    WeakPtr<BlockLegacy> mLegacyBlock;

public:
    virtual ~Block();

    const DataID& getDataDEPRECATED() const {
        return mData;
    }
};