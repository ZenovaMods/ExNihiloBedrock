#pragma once

#include "ActorRenderer.h"
#include "AppPlatformListener.h"
#include "Mesh.h"

class Item;
struct TextureUVCoordinateSet;

class ItemSpriteRenderer : public ActorRenderer, public AppPlatformListener {
public:
	Item* mItem;
	mce::Mesh mMesh;
	bool mGlint;

	ItemSpriteRenderer(mce::TextureGroup&, Item*, bool);
	virtual void onAppSuspended();
	virtual ~ItemSpriteRenderer();
	virtual void render(BaseActorRenderContext&, ActorRenderData&);
	virtual const TextureUVCoordinateSet& getIcon(Actor&) const;
	virtual bool isGlint(const Actor&) const;
	void _buildQuad(BaseActorRenderContext&, Actor&, mce::Mesh&);
	void _renderQuad(BaseActorRenderContext&, Actor&, mce::Mesh&, Vec3 const&, float, float);
};