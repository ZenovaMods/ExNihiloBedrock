#pragma once

#include "../actor/ActorUniqueID.h"
#include "Direction.h"
#include "Facing.h"
#include "Vec3.h"
#include "../world/BlockPos.h"

enum class Mirror : unsigned char;
enum class Rotation : unsigned char;

enum class DataLoadHelperType : int {
    Default,
    Structure
};

class DataLoadHelper {
public:
    virtual ~DataLoadHelper() = default;
    virtual Vec3 loadPosition(const Vec3&) = 0;
    virtual BlockPos loadBlockPosition(const BlockPos&) = 0;
    virtual BlockPos loadBlockPositionOffset(const BlockPos&) = 0;
    virtual float loadRotationDegreesX(float) = 0;
    virtual float loadRotationDegreesY(float) = 0;
    virtual float loadRotationRadiansX(float) = 0;
    virtual float loadRotationRadiansY(float) = 0;
    virtual FacingID loadFacingID(FacingID) = 0;
    virtual Vec3 loadDirection(const Vec3&) = 0;
    virtual Direction::Type loadDirection(Direction::Type) = 0;
    virtual Rotation loadRotation(Rotation) = 0;
    virtual Mirror loadMirror(Mirror) = 0;
    virtual ActorUniqueID loadActorUniqueID(ActorUniqueID) = 0;
    virtual ActorUniqueID loadOwnerID(ActorUniqueID) = 0;
    virtual DataLoadHelperType getType() const = 0;
    virtual bool shouldResetTime() = 0;
};