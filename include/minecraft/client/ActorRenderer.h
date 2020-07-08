#pragma once

#include "../util/AABB.h"

class Actor;
class Color;
class BaseActorRenderContext;
class ActorRenderData;

namespace mce {
	class TextureGroup;
	class MaterialPtr {
	public:
		char mMaterialInfo[0x10];
	};
	class TexturePtr {
	public:
		char filler[0x48];
	};
}

class ActorShaderManager {
public:
	mce::MaterialPtr mEntityMaterial;
	mce::MaterialPtr mTransparentEntityMaterial;
	mce::MaterialPtr mStaticMaterial;

	virtual ~ActorShaderManager();
	virtual Color _getOverlayColor(Actor&, float) const;
	static Color getOverlayColor(Actor&, float);
};

class BaseActorRenderer : ActorShaderManager {
public:
	mce::MaterialPtr mNameTagMaterial;
	mce::MaterialPtr mDepthTestedNameTagMaterial;
	mce::MaterialPtr mDepthTestedNameTextMaterial;

	virtual ~BaseActorRenderer();
};

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