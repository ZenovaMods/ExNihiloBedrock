#pragma once

#include "minecraft/blockactor/BlockActor.h"

class BlockActorInfestedLeaves : public BlockActor {
protected:
	static uint64_t tileId;
	bool hasNearbyLeaves;
	int updateIndex;

public:
	BlockActorInfestedLeaves(BlockActorType, const BlockPos&, const std::string&);
	BlockActorInfestedLeaves(const BlockPos&);
	virtual void tick(BlockSource&);
};