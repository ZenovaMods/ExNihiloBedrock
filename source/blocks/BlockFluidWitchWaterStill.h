#pragma once

#include "minecraft/block/LiquidBlockStatic.h"

class BlockFluidWitchWaterStill : public LiquidBlockStatic {
public:
	BlockFluidWitchWaterStill(const std::string&, int);

	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual void entityInside(BlockSource&, const BlockPos&, Actor&) const;
	virtual void _setDynamic(BlockSource&, const BlockPos&) const;
};

extern void EntityInWitchWater(BlockSource&, const BlockPos&, Actor&);