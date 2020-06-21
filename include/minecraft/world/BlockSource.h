#pragma once

#include <thread>
#include <memory>

struct ActorBlockSyncMessage;
class Level;
class BlockPos;

class BlockSource {
private:
    const std::thread::id mOwnerThreadID;
    const bool mAllowUnpopulatedChunks;
    const bool mPublicSource;
    Level& mLevel;

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
    bool setBlock(const BlockPos&, const Block&, int, const ActorBlockSyncMessage*);
    const Block& getBlock(const BlockPos&) const;
};