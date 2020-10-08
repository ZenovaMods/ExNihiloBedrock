#pragma once

#include "minecraft/block/ActorBlock.h"

class BlockBarrel : public BlockLegacy {
private:
	const int tier;
public:
	BlockBarrel(const std::string&, int, int, MaterialType);
};