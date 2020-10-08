#pragma once

#include "Vec3.h"

class AABB {
public:
    Vec3 min;
    Vec3 max;
private:
    bool empty;

public:
    AABB() : min(0.0f), max(1.0f), empty(false) {};

    AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) :
        min(minX, minY, minZ),
        max(maxX, maxY, maxZ)
    {
        empty = min == Vec3::ZERO && max == Vec3::ZERO;
    }

    AABB(const Vec3& min, const Vec3& max) :
        min(min),
        max(max)
    {
        empty = min == Vec3::ZERO && max == Vec3::ZERO;
    }
};