#pragma once

#include <memory>
#include <string>

#include "../world/BlockPos.h"
#include "CompoundTag.h"

class Packet {
protected:
    char filler[0x1C];

public:
    virtual ~Packet();
};

class NetworkBlockPosition : public BlockPos {};

class BlockActorDataPacket : public Packet {
public:
    NetworkBlockPosition mPos;
    CompoundTag mData;

    BlockActorDataPacket(const BlockPos&, CompoundTag);
};