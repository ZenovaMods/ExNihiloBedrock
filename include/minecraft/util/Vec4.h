#pragma once

class Vec4 {
public:
    float x;
    float y;
    float z;
    float w;

    Vec4() : Vec4(0, 0, 0, 0) {}
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};