#pragma once

#include "Mob.h"

class Monster : public Mob {
    ActorUniqueID mLastHurtByMobId;

public:
    virtual void aiStep();
    virtual void normalTick();
    virtual bool isDarkEnoughToSpawn() const;
    virtual bool checkSpawnRules(bool);
    virtual bool canExistInPeaceful() const;
    virtual bool shouldDespawn() const;
    virtual float _getWalkTargetValue(const BlockPos&);
    virtual bool _hurt(const ActorDamageSource&, int, bool, bool);
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
    virtual Actor* findAttackTarget();
};