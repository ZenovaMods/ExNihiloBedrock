#pragma once

#include <stack>

#include "../util/AABB.h"
#include "IClientInstance.h"
#include "ScreenContext.h"
#include "MatrixStack.h"
#include "Camera.h"

class ActorBlockRenderer;
class ActorRenderDispatcher;
class BlockActorRenderDispatcher;
class ItemRenderer;
class ItemInHandRenderer;
class MinecraftGame;
class ParticleSystemEngine;
class ScreenContext;

class BaseActorRenderContext {
public:
	float mPartialTicks;
	int64_t mIdk;
	IClientInstance& mClient;
	MinecraftGame& mMinecraft;
	ScreenContext& mScreenContext;
	BlockActorRenderDispatcher& mBlockEntityRenderDispatcher;
	ActorRenderDispatcher& mEntityRenderDispatcher;
	ActorBlockRenderer& mEntityBlockRenderer;
	ItemInHandRenderer& mItemInHandRenderer;
	ItemRenderer& mItemRenderer;
	ParticleSystemEngine& mParticleSystemEngine;
	Vec3 mCameraPosition;
	Vec3 mTargetPosition;
	AABB mClipRegion;
	bool mIgnoreLightning;
	int64_t mIdk2;
	int64_t mFiller[60];

	virtual ~BaseActorRenderContext();

	ScreenContext& getScreenContext() { return mScreenContext; }
	IClientInstance& getClient() { return mClient; }
	bool isIgnoringLightning() { return mIgnoreLightning; }
	Tessellator& getTessellator() { return mScreenContext.mTessellator; }
	MatrixStack& getWorldMatrix() { return mScreenContext.mMeshContext.mCamera.mWorld; }
	MatrixStack& getViewMatrix() { return mScreenContext.mMeshContext.mCamera.mModel; }
	MatrixStack& getProjectionMatrix() { return mScreenContext.mMeshContext.mCamera.mProjection; }
	LightTexture* getLightTexture() { return mClient.getLightTexture(); }
};