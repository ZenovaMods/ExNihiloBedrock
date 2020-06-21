#pragma once

#include "../util/Vec3.h"
#include "../util/Vec2.h"

class Actor;

class MovementInterpolator {
    Vec3 mPos = Vec3::ZERO;
    Vec2 mRot = Vec2::ZERO;
    float mHeadYaw = 0.0F;
    int mPositionSteps = 0;
    int mRotationSteps = 0;
    int mHeadYawSteps = 0;
    bool mInterpolationActive = true;

public:
    MovementInterpolator() = default;
    int getPositionSteps() const { return mPositionSteps; }
    int getRotationSteps() const { return mRotationSteps; }
};