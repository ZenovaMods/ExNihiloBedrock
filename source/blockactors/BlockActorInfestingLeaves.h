#pragma once

#include "BlockActorInfestedLeaves.h"
#include "minecraft/util/Color.h"

class BlockActorInfestingLeaves : public BlockActorInfestedLeaves {
protected:
	float progress;

public:
	BlockActorInfestingLeaves(const BlockPos&);
	virtual void load(Level&, const CompoundTag&, DataLoadHelper&);
	virtual bool save(CompoundTag&) const;
	virtual void tick(BlockSource&);
	virtual std::unique_ptr<Packet> getUpdatePacket(BlockSource&);
	virtual void onChanged(BlockSource&);
	virtual void _onUpdatePacket(const CompoundTag&, BlockSource&);

	int getLeafColor(int) const;
	float getProgress() const { return progress; }
};