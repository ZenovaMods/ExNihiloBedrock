#pragma once

#include "Vec3.h"

class AABB {
public:
    Vec3 min;
    Vec3 max;
private:
    bool empty;
};