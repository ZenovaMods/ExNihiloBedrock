#pragma once

#include "../util/AABB.h"

class Actor;
class Color;

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
};

class DataDrivenRenderer : public ActorRenderer {
public:

};