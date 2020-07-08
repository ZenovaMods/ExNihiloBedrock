#pragma once

#include "Monster.h"
#include "ParticleType.h"

class Slime : public Monster {
protected:
    float mTargetSquish;
    ParticleType mParticleType;
private:
    float mSquish;
    float mOldSquish;

public:
    virtual void reloadHardcoded(Actor::InitializationMethod, const VariantParameterList&);
    virtual void aiStep();
    virtual void normalTick();
    virtual bool canDealDamage();
    virtual LevelSoundEvent getSquishSound();
    virtual float getShadowRadius() const;
    virtual bool useNewAi() const;
    virtual void onSynchedDataUpdate(int);
    virtual void playerTouch(Player&);
    virtual void remove();
    virtual bool checkSpawnRules(bool);
    virtual void setSlimeSize(int);
    virtual bool doPlayJumpSound();
    virtual bool doPlayLandSound();
    virtual void playJumpSound();
    virtual void playLandSound();
    virtual float _getWalkTargetValue(const BlockPos&);
    virtual Actor* findAttackTarget();
    virtual void decreaseSquish();
    virtual Unique<Slime> createChild(int);
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);

    int getSlimeSize() const { return getVariant(); }
};