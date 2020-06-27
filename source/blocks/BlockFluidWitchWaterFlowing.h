#pragma once

#include "minecraft/block/LiquidBlockDynamic.h"

class BlockFluidWitchWaterFlowing : public LiquidBlockDynamic {
public:
	BlockFluidWitchWaterFlowing(const std::string&, int);

	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual void _setStatic(BlockSource&, const BlockPos&, bool) const;
};