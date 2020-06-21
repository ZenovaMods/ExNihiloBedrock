#pragma once

#include "Actor.h"
#include "ParticleType.h"
#include "MovementInterpolator.h"

class Mob;
class HitResult;

class Throwable : public Actor {
protected:
    bool mInGround;
    ActorUniqueID mOwnerId;
private:
    int mShakeTime;
    int mLife;
    MovementInterpolator mInterpolation;

public:
    Throwable(ActorDefinitionGroup*, const ActorDefinitionIdentifier&);
    virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList&);
    virtual void normalTick();
    virtual void lerpMotion(const Vec3&);
    virtual void lerpTo(const Vec3&, const Vec2&, int);
    virtual float getThrowPower();
    virtual bool stopUponGroundCollision() const;
    virtual float getShadowHeightOffs();
    virtual ActorUniqueID getSourceUniqueID() const;
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
    virtual bool canMakeStepSound() const;
    virtual float getThrowUpAngleOffset();
    virtual float getGravity();
    virtual ParticleType getParticleType();
    virtual void onHit(const HitResult&);
};