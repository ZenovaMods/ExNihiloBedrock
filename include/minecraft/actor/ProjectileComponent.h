#pragma once

#include <cstdint>
#include <vector>

#include "../util/HitResult.h"
#include "../world/LevelEvent.h"
#include "ActorType.h"
#include "ParticleType.h"
#include "ActorUniqueID.h"

class OnHitSubcomponent;
class VariantParameterList;

class ActorFilterGroup {
public:
	virtual bool _handleUnknownMember(const std::string&, const Json::Value&);
};

class DefinitionTrigger {
public:
	std::string mType;
	std::string mTarget;
	ActorFilterGroup mFilter;

	bool canTrigger(const Actor&, const VariantParameterList&) const;
};

enum class ProjectileAnchor : int {
	Origin,
	EyeHeight,
	Middle,
	Count
};

class ProjectileComponent {
private:
	enum EAxis { NONE = -1, X, Y, Z };

	bool mWasOnGround;
	bool mNoPhysics;
	ActorUniqueID mOwnerId;
	Vec3 mThrownPos;
	Vec3 mApexPos;
	bool mFoundApex;
	int mLife;
	int mFlightTime;
	int mOnGroundTime;
	int mShakeTime;
	BlockPos mBlock;
	BlockPos mStuckToBlockPos;
	Vec3 mCollisionPos;
	int mEnchantPower;
	int mEnchantImpaler;
	HitResult mHitResult;
	FacingID mHitFacing;
	bool mReflect;
	float mPower;
	float mDamage;
	Vec3 mOffset;
	ParticleType mHitParticle;
	float mGravity;
	float mUpwardsAngleOffset;
	std::vector<OnHitSubcomponent*> mOnHitCommands;
	DefinitionTrigger mOnHitEvent;
	float mUncertaintyBase;
	float mUncertaintyMultiplier;
	ActorType mFilterType;
	float mOnFireTime;
	int mPotionEffect;
	float mSplashRange;
	bool mKnockback;
	float mKnockbackForce;
	bool mCatchFire;
	bool mChanneling;
	bool mIsSplash;
	float mInertiaMod;
	float mLiquidInertia;
	bool mSemiRandomDiffDamage;
	ProjectileAnchor mSpawnPosAnchor;
	LevelSoundEvent mHitEntitySound;
	LevelSoundEvent mHitGroundSound;
	LevelSoundEvent mShootSound;
	bool mIsDangerous;
	bool mShootTarget;
	bool mDamageOwner;
	bool mReflectOnHurt;
	bool mDestroyOnHurt;
	bool mStopOnHit;
	bool mCritParticleOnHurt;
	bool mHitWater;
	bool mHitActor;
	bool mMultipleHits;
	int mPiercingEnchantLevel;
	int mActorHitCount;
	bool mIsHoming;
	ActorUniqueID mPendingTargetID;
	Actor* mTarget;
	ActorUniqueID mTargetID;
	Vec3 mTargetDelta;
	int mFlightSteps;
	EAxis mCurrentMoveDirection;
	bool mShouldBounce;
	unsigned int mCurrentDelay;
	bool mWaitingForServer;
	bool mWaitingForServerHitGround;
	HitResult mCachedHitResult;
	bool mDelayOneFrame;

public:
	HitResult getHitResult() const { return mHitResult; }
};