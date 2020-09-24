#pragma once

#include "DataLoadHelper.h"

class DefaultDataLoadHelper : public DataLoadHelper {
public:
    virtual Vec3 loadPosition(const Vec3&);
    virtual BlockPos loadBlockPosition(const BlockPos&);
    virtual BlockPos loadBlockPositionOffset(const BlockPos&);
    virtual float loadRotationDegreesX(float);
    virtual float loadRotationDegreesY(float);
    virtual float loadRotationRadiansX(float);
    virtual float loadRotationRadiansY(float);
    virtual FacingID loadFacingID(FacingID);
    virtual Vec3 loadDirection(const Vec3&);
    virtual Direction::Type loadDirection(Direction::Type);
    virtual Rotation loadRotation(Rotation);
    virtual Mirror loadMirror(Mirror);
    virtual ActorUniqueID loadActorUniqueID(ActorUniqueID);
    virtual ActorUniqueID loadOwnerID(ActorUniqueID);
    virtual bool shouldResetTime();
    virtual DataLoadHelperType getType() const;
};