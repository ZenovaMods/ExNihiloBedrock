#pragma once

#include "BlockLegacy.h"
#include "../world/BlockSource.h"
#include "../util/SharedPtr.h"
#include "../util/CompoundTag.h"

typedef CompoundTag BlockSerializationId;

class Block {
private:
    const DataID mData;
    WeakPtr<BlockLegacy> mLegacyBlock;
    BlockSerializationId mSerializationId;
    BlockRuntimeId mRuntimeId;
    bool mHasRuntimeId;

public:
    virtual ~Block();

    bool isSolid() const {
        return mLegacyBlock->mSolid;
    }

    const BlockLegacy& getLegacyBlock() const;

    const Block& getDefaultState() const {
        return mLegacyBlock->getDefaultState();
    }
    const Material& getMaterial() const {
        return mLegacyBlock->getMaterial();
    }
    bool canContainLiquid() const {
        return mLegacyBlock->canContainLiquid();
    }
    void spawnResources(BlockSource& region, const BlockPos& pos, float explosionRadius, int bonusLootLevel) const {
        mLegacyBlock->spawnResources(region, pos, region.getBlock(pos), explosionRadius, bonusLootLevel);
    }
    void spawnResources(BlockSource& region, const BlockPos& pos, const Block& block, float explosionRadius, int bonusLootLevel) const {
        mLegacyBlock->spawnResources(region, pos, block, explosionRadius, bonusLootLevel);
    }

    const BlockRuntimeId& getRuntimeId() const {
        return mRuntimeId;
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