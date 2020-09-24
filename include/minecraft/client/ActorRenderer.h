#pragma once

#include "BaseActorRenderer.h"
#include "../util/AABB.h"

class BaseActorRenderContext;
class ActorRenderData;

class ActorRenderer : public BaseActorRenderer {
public:
	bool mBool1;
	bool mHasWaterHole;
	short mShort1;
	mce::MaterialPtr mAlphatestMaterial;
	mce::MaterialPtr mGlintItemMaterial;
	mce::TexturePtr mGlintTexture;
	mce::TexturePtr mTerrainTexture;
	mce::TextureGroup& mTextureGroup;
	AABB mRenderBounds;
	void* mFiller;
	mce::MaterialPtr mLeadBaseMaterial;
	char filler[0x1B0];
	
	virtual ~ActorRenderer();
	virtual void render(BaseActorRenderContext&, ActorRenderData&) = 0;
	virtual void renderDebug(BaseActorRenderContext&, ActorRenderData&);
	virtual void renderEffects(BaseActorRenderContext&, ActorRenderData&);
	virtual void renderTrading(BaseActorRenderContext&, ActorRenderData&, float);
	virtual void renderFlame(BaseActorRenderContext&, ActorRenderData&);
	virtual void renderLeash(BaseActorRenderContext&, ActorRenderData&);
	virtual void renderWaterHole(BaseActorRenderContext&, ActorRenderData&);
	virtual void addAdditionalRenderingIfNeeded(mce::TextureGroup&);
	virtual AABB getRenderBounds(const Actor&) const;
	virtual void* getLeashOffset(Actor&, float, float, float, bool, bool);
};

class DataDrivenRenderer : public ActorRenderer {
public:

};