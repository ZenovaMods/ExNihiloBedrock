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

	static Color fromABGR(int col) {
		return from255Range((col) & 0xFF, (col >> 8) & 0xFF, (col >> 16) & 0xFF, (col >> 24) & 0xFF);
	}

	static Color fromARGB(int col) {
		return from255Range((col >> 16) & 0xFF, (col >> 8) & 0xFF, (col) & 0xFF, (col >> 24) & 0xFF);
	}

	static Color fromRGB(int col) {
		return from255Range((col >> 16) & 0xFF, (col >> 8) & 0xFF, (col) & 0xFF, 255);
	}

	template<typename T>
	static Color from255Range(T r, T g, T b, T a) {
		return { r / 255.0F, g / 255.0F, b / 255.0F, a / 255.0F };
	}
};

inline const Color Color::NIL{ 0.0, 0.0, 0.0, 0.0 };