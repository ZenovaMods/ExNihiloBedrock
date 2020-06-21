#pragma once

#include "minecraft/actor/Throwable.h"

class ProjectileStone : public Throwable {
public:
	ProjectileStone(ActorDefinitionGroup*, const ActorDefinitionIdentifier&);
	virtual void setAuxValue(int);
	virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
	virtual void addAdditionalSaveData(CompoundTag&);

	short getStoneType() const;
};