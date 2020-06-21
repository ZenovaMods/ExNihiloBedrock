#pragma once

#include <memory>

class BlockActor;
class BlockSource;
class BlockPos;
class Block;
class Actor;
struct ActorBlockSyncMessage;

class BlockSourceListener {
public:
    virtual ~BlockSourceListener() {}
    virtual void onSourceCreated(BlockSource&) {}
    virtual void onSourceDestroyed(BlockSource&) {}
    virtual void onAreaChanged(BlockSource&, const BlockPos&, const BlockPos&) {}
    virtual void onBlockChanged(BlockSource&, const BlockPos&, uint32_t, const Block&, const Block&, int, const ActorBlockSyncMessage*) {}
    virtual void onBrightnessChanged(BlockSource&, const BlockPos&) {}
    virtual void onBlockEntityChanged(BlockSource&, BlockActor&) {}
    virtual void onBlockEntityAboutToBeRemoved(BlockSource&, std::shared_ptr<BlockActor>) {}
    virtual void onEntityChanged(BlockSource&, Actor&) {}
    virtual void onBlockEvent(BlockSource&, int, int, int, int, int) {}
};