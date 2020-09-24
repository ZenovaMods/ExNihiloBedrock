#pragma once

#include "BlockLegacy.h"

class LeafBlock : public BlockLegacy {
public:
	static bool isDeepLeafBlock(BlockSource&, const BlockPos&);
};