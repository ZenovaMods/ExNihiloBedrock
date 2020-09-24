#pragma once

#include "BlockActorInfestedLeaves.h"

class BlockActorInfestingLeaves : public BlockActorInfestedLeaves {
protected:
	float progress;
	const Block* leafBlock;

public:
	BlockActorInfestingLeaves(const BlockPos&);
	virtual void load(Level&, const CompoundTag&, DataLoadHelper&);
	virtual bool save(CompoundTag&) const;
	virtual void tick(BlockSource&);
	virtual std::unique_ptr<Packet> getUpdatePacket(BlockSource&);
	virtual void onChanged(BlockSource&);
	virtual void _onUpdatePacket(const CompoundTag&, BlockSource&);

	float getProgress() const { return progress; }
	const Block* getLeafBlock() const { return leafBlock; }
	void setLeafBlock(const Block* block) { leafBlock = block; setChanged(); }
};