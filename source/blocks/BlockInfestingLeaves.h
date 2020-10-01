#pragma once

#include "BlockInfestedLeaves.h"

class BlockInfestingLeaves : public BlockInfestedLeaves {
public:
	BlockInfestingLeaves(const std::string&, int);
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual int getColor(BlockSource&, const BlockPos&, const Block&) const;
	virtual bool isSeasonTinted(const Block&, BlockSource&, const BlockPos&) const;
	virtual void playerDestroy(Player&, const BlockPos&, const Block&) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
	virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos&) const;

	Color getSeasonsColor(BlockSource&, const BlockPos&, int, int) const;
	static void infestLeafBlock(BlockSource&, const BlockPos&);
	static const Block& getBlockForLeaf(const Block& leafBlock, bool infesting = false);
};

class BlockInfestingLeavesOld : public BlockInfestingLeaves {
public:
	BlockInfestingLeavesOld(const std::string&, int);
	virtual int getVariant(const Block&) const;
	virtual BlockLegacy& init();
};

class BlockInfestingLeavesNew : public BlockInfestingLeaves {
public:
	BlockInfestingLeavesNew(const std::string&, int);
	virtual int getVariant(const Block&) const;
	virtual BlockLegacy& init();
};