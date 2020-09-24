#pragma once

#include "BlockLegacy.h"

class ActorBlock : public BlockLegacy {
public:
    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual void triggerEvent(BlockSource&, const BlockPos&, int, int) const;
    virtual void spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
    virtual ItemInstance getEntityResourceItem(Random&, const BlockActor&, int) const;
    virtual bool playerWillDestroy(Player&, const BlockPos&, const Block&) const;
    virtual bool canBeSilkTouched() const;
protected:
    ActorBlock(const std::string& nameId, int id, const Material& material) : BlockLegacy(nameId, id, material) {}

public:
    virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos&) const = 0;
};