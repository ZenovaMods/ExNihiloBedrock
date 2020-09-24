#pragma once

#include "minecraft/client/MovingBlockActorRenderer.h"

class InfestingLeavesRenderer : public MovingBlockActorRenderer {
public:
	InfestingLeavesRenderer(mce::TextureGroup& textures, BlockTessellator& tessellator) : MovingBlockActorRenderer(textures, tessellator) {}
	virtual void render(BaseActorRenderContext&, BlockActorRenderData&);
};