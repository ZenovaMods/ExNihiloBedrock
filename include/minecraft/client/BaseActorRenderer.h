#pragma once

#include "MaterialPtr.h"
#include "TexturePtr.h"

class Actor;
class BaseActorRenderContext;
class BlockPos;
class BlockSource;
class Color;
class LightTexture;
class ScreenContext;
class Vec2;
class Vec4;

namespace mce {
	class TextureGroup;
}

class ActorShaderManager {
public:
	mce::MaterialPtr mEntityMaterial;
	mce::MaterialPtr mTransparentEntityMaterial;
	mce::MaterialPtr mStaticMaterial;

	virtual ~ActorShaderManager();
	virtual Color _getOverlayColor(Actor&, float) const;
	static Color getOverlayColor(Actor&, float);
	static void setupShaderParameters(ScreenContext&, float, const Color&, bool);
	static void setupShaderParameters(ScreenContext&, BaseActorRenderContext&, Actor&, const Color&, const Color&, const Color&, const Color&, float, float, float, float, const Vec2&, const Vec4&, float, bool);
	static void setupShaderParameters(ScreenContext&, const Color&, const Color&, const Color&, const Color&, float, float, float, float, const Vec2&, const Vec4&, float);
	static void setupShaderParameters(ScreenContext&, BlockSource&, const BlockPos&, float, bool, LightTexture&, const Vec2&, const Vec4&);
};

class BaseActorRenderer : public ActorShaderManager {
public:
	mce::MaterialPtr mNameTagMaterial;
	mce::MaterialPtr mDepthTestedNameTagMaterial;
	mce::MaterialPtr mDepthTestedNameTextMaterial;

	BaseActorRenderer();
	virtual ~BaseActorRenderer();
};
