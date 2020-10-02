#pragma once

class Vec2 {
public:

	float x, y;

	Vec2() { x = y = 0.0; }
	Vec2(float x, float y) : x(x), y(y) { }

	static Vec2 ZERO;
	static Vec2 ONE;
	static Vec2 UNIT_X;
	static Vec2 NEG_UNIT_X;
	static Vec2 UNIT_Y;
	static Vec2 NEG_UNIT_Y;
	static Vec2 MAX;
	static Vec2 MIN;

};

inline Vec2 Vec2::ZERO{};
inline Vec2 Vec2::ONE{ 1.0f, 1.0f };
