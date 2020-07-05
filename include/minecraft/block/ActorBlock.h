#pragma once

#include "BlockLegacy.h"

class ActorBlock : public BlockLegacy {
public:
    Shared<BlockActor> newBlockEntity(const BlockPos&, const Block&) const;
    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual void triggerEvent(BlockSource&, const BlockPos&, int, int) const;
    virtual void spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
    virtual ItemInstance getEntityResourceItem(Random&, const BlockActor&, int) const;
    virtual bool playerWillDestroy(Player&, const BlockPos&, const Block&) const;
protected:
    virtual bool canBeSilkTouched() const;
    ActorBlock(const std::string&, int, const Material&);
};