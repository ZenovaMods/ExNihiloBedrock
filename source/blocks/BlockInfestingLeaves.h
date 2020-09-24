#pragma once

#include "minecraft/block/ActorBlock.h"

class BlockInfestingLeaves : public ActorBlock {
protected:
	bool mHasTransparentLeaves = false;
	bool mHasFastAlphaTest = false;

public:
	BlockInfestingLeaves(const std::string&, int);
	virtual bool canProvideSupport(const Block&, FacingID, BlockSupportType) const;
	virtual bool canContainLiquid() const;
	virtual bool breaksFallingBlocks(const Block&) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual int getColor(BlockSource&, const BlockPos&, const Block&) const;
	virtual BlockRenderLayer getRenderLayer(const Block&, BlockSource&, const BlockPos&) const;
	virtual bool isAuxValueRelevantForPicking() const;
	virtual bool isSeasonTinted(const Block&, BlockSource&, const BlockPos&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual int getResourceCount(Random&, const Block&, int) const;
	virtual void playerDestroy(Player&, const BlockPos&, const Block&) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
	virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos&) const;

	Color getSeasonsColor(BlockSource&, const BlockPos&, int, int) const;
	static void infestLeafBlock(BlockSource&, const BlockPos&);
};