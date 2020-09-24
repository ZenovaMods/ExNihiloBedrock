#pragma once

#include "BlockActorRenderer.h"

class BlockTessellator;
namespace mce { class TextureGroup; }

class MovingBlockActorRenderer : public BlockActorRenderer {
public:
	BlockTessellator& mBlockTessellator;
	mce::TexturePtr mTerrainTexture;
	mce::MaterialPtr mRenderLayerMaterials[11];

	MovingBlockActorRenderer(mce::TextureGroup&, BlockTessellator&);
	virtual ~MovingBlockActorRenderer() {}
	virtual void render(BaseActorRenderContext&, BlockActorRenderData&);
};