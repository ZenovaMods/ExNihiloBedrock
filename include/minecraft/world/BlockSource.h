#pragma once

#include <thread>
#include <memory>

struct ActorBlockSyncMessage;
class Level;
class ChunkSource;
class Dimension;
class BlockPos;
class ItemStack;

class BlockSource {
private:
    const std::thread::id mOwnerThreadID;
    const bool mAllowUnpopulatedChunks;
    const bool mPublicSource;
    Level& mLevel;
    ChunkSource& mChunkSource;
    Dimension& mDimension;

public:
    virtual ~BlockSource();
    Level& getLevel() const {
        return mLevel;
    }
    Level& getLevel() {
        return mLevel;
    }
    const Level& getLevelConst() const {
        return mLevel;
    }
    Dimension& getDimension() const {
        return mDimension;
    }
    Dimension& getDimension() {
        return mDimension;
    }
    const Dimension& getDimensionConst() const {
        return mDimension;
    }
    bool setLiquidBlock(const BlockPos& pos, const Block& block, bool useExtraData, int updateFlags) {
        if (useExtraData)
            return setExtraBlock(pos, block, updateFlags);
        else
            return setBlock(pos, block, updateFlags, nullptr);
    }
    void addToTickingQueue(const BlockPos&, const Block&, int, int);
    bool setExtraBlock(const BlockPos&, const Block&, int);
    bool setBlock(const BlockPos&, const Block&, int, const ActorBlockSyncMessage*);
    bool removeBlock(const BlockPos& pos);
    const Block& getBlock(const BlockPos&) const;
    const Block& getLiquidBlock(const BlockPos&) const;
    const Block& getExtraBlock(const BlockPos&) const;
    bool checkBlockPermissions(Actor&, const BlockPos&, FacingID, const ItemStack&, bool);
};