#pragma once

#include "BlockTessellatorRegistry.h"

class BlockBarrelRenderer : public Zenova::BlockRenderer {
public:
	BlockBarrelRenderer() : Zenova::BlockRenderer() {}
	virtual bool renderInWorld(BlockTessellator*, Tessellator&, const Block&, const BlockPos&);
};