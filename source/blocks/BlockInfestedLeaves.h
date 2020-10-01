#pragma once

#include "minecraft/block/ActorBlock.h"

class BlockInfestedLeaves : public ActorBlock {
protected:
	bool mHasTransparentLeaves = false;
	bool mHasFastAlphaTest = false;

public:
	BlockInfestedLeaves(const std::string&, int);
	virtual bool canProvideSupport(const Block&, FacingID, BlockSupportType) const;
	virtual bool canContainLiquid() const;
	virtual bool breaksFallingBlocks(const Block&) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual BlockRenderLayer getRenderLayer(const Block&, BlockSource&, const BlockPos&) const;
	virtual bool isAuxValueRelevantForPicking() const;
	virtual int getColor(BlockSource&, const BlockPos&, const Block&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual int getResourceCount(Random&, const Block&, int) const;
	virtual void playerDestroy(Player&, const BlockPos&, const Block&) const;
	virtual void spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
	virtual std::shared_ptr<BlockActor> newBlockEntity(const BlockPos&) const;
};

class BlockInfestedLeavesOld : public BlockInfestedLeaves {
public:
	BlockInfestedLeavesOld(const std::string&, int);
	virtual int getVariant(const Block&) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
	virtual ItemInstance getSilkTouchItemInstance(const Block&) const;
	virtual std::string buildDescriptionId(const Block&) const;
	virtual BlockLegacy& init();
};

class BlockInfestedLeavesNew : public BlockInfestedLeaves {
public:
	BlockInfestedLeavesNew(const std::string&, int);
	virtual int getVariant(const Block&) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
	virtual ItemInstance getSilkTouchItemInstance(const Block&) const;
	virtual std::string buildDescriptionId(const Block&) const;
	virtual BlockLegacy& init();
};