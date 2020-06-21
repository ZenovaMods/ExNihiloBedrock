#include "ProjectileStone.h"

#include "minecraft/util/CompoundTag.h"

ProjectileStone::ProjectileStone(ActorDefinitionGroup* definitions, const ActorDefinitionIdentifier& definitionName) : Throwable(definitions, definitionName) {
	mEntityData.define<short>(0x24, 0);
}

void ProjectileStone::setAuxValue(int aux) {
	mEntityData.set<short>(0x24, aux);
}

void ProjectileStone::readAdditionalSaveData(const CompoundTag& tag, DataLoadHelper& dataLoadHelper) {
	Throwable::readAdditionalSaveData(tag, dataLoadHelper);
	short aux = tag.getShort("PebbleId");
	setAuxValue(aux);
}

void ProjectileStone::addAdditionalSaveData(CompoundTag& tag) {
	Throwable::addAdditionalSaveData(tag);
	tag.putShort("PebbleId", getStoneType());
}

short ProjectileStone::getStoneType() const {
	return mEntityData.getShort(0x24);
}
