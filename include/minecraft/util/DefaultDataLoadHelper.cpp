#include "DefaultDataLoadHelper.h"

Vec3 DefaultDataLoadHelper::loadPosition(const Vec3& position) {
	return position;
}

BlockPos DefaultDataLoadHelper::loadBlockPosition(const BlockPos& blockPos) {
	return blockPos;
}

BlockPos DefaultDataLoadHelper::loadBlockPositionOffset(const BlockPos& blockPosOffset) {
	return blockPosOffset;
}

float DefaultDataLoadHelper::loadRotationDegreesX(float x) {
	return x;
}

float DefaultDataLoadHelper::loadRotationDegreesY(float y) {
	return y;
}

float DefaultDataLoadHelper::loadRotationRadiansX(float x) {
	return x;
}

float DefaultDataLoadHelper::loadRotationRadiansY(float y) {
	return y;
}

FacingID DefaultDataLoadHelper::loadFacingID(FacingID facing) {
	return facing;
}

Vec3 DefaultDataLoadHelper::loadDirection(const Vec3& direction) {
	return direction;
}

Direction::Type DefaultDataLoadHelper::loadDirection(Direction::Type direction) {
	return direction;
}

Rotation DefaultDataLoadHelper::loadRotation(Rotation rotation) {
	return rotation;
}

Mirror DefaultDataLoadHelper::loadMirror(Mirror mirror) {
	return mirror;
}

ActorUniqueID DefaultDataLoadHelper::loadActorUniqueID(ActorUniqueID id) {
	return id;
}

ActorUniqueID DefaultDataLoadHelper::loadOwnerID(ActorUniqueID id) {
	return id;
}

DataLoadHelperType DefaultDataLoadHelper::getType() const {
	return DataLoadHelperType::Default;
}

bool DefaultDataLoadHelper::shouldResetTime() {
	return false;
}
