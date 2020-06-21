#pragma once

#include "../world/BlockPos.h"
#include "Vec3.h"

class Actor;

typedef unsigned char FacingID;

enum HitResultType {
    TILE,
    ENTITY,
    ENTITY_OUT_OF_RANGE,
    NO_HIT
};

class HitResult {
public:
    Vec3 mStartPos;
    Vec3 mRayDir;
    HitResultType mType;
    FacingID mFacing;
    BlockPos mBlock;
    Vec3 mPos;
    Actor* mEntity;
    bool mIsHitLiquid;
    FacingID mLiquidFacing;
    BlockPos mLiquid;
    Vec3 mLiquidPos;
    bool mIndirectHit;

public:
    HitResult() = default;
    const Vec3& getPos() const { return mPos; }
    HitResultType getHitResultType() { return mType; }
};