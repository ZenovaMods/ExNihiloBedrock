#pragma once

#include <memory>

#include "BlockActorType.h"

class BlockActor;
class BlockLegacy;
class BlockPos;

class BlockActorFactory {
public:
    static std::shared_ptr<BlockActor> createBlockEntity(BlockActorType, const BlockPos&, const BlockLegacy&);
};