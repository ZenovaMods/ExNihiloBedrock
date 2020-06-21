#pragma once

#include <array>
#include <string>

class Color {
public:
    static const Color NIL;

    float r;
    float g;
    float b;
    float a;

    Color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}
};

inline const Color Color::NIL{ 0.0, 0.0, 0.0, 0.0 };