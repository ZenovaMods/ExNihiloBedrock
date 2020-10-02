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
};