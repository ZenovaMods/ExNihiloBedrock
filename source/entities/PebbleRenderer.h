#pragma once

#include "minecraft/client/ItemSpriteRenderer.h"

class PebbleRenderer : public ItemSpriteRenderer {
public:
	mce::Mesh mTextureMeshes[4];

	PebbleRenderer(mce::TextureGroup& textures, Item* item) : ItemSpriteRenderer(textures, item, false), mTextureMeshes() {}
	virtual void onAppSuspended();
	virtual void render(BaseActorRenderContext&, ActorRenderData&);
	virtual const TextureUVCoordinateSet& getIcon(Actor&) const;
};