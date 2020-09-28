#pragma once

#include "minecraft/block/BlockRenderLayer.h"
#include "minecraft/client/Mesh.h"
#include "minecraft/client/MovingBlockActorRenderer.h"

class Block;
class BlockPos;
class BlockActorInfestingLeaves;

class InfestingLeavesRenderer : public MovingBlockActorRenderer {
public:
	InfestingLeavesRenderer(mce::TextureGroup& textures, BlockTessellator& tessellator) : MovingBlockActorRenderer(textures, tessellator) {}
	virtual void render(BaseActorRenderContext&, BlockActorRenderData&);
	mce::Mesh getBlockMesh(BlockTessellator&, Tessellator&, const Block&, BlockPos&, BlockRenderLayer, const BlockActorInfestingLeaves&);
};