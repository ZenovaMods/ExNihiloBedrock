#pragma once

#include "Vec2.h"
#include "../world/BlockPos.h"
#include <sstream>

class Pos;

class Vec3 {
public:

	float x, y, z;

	Vec3(float s) {
		x = s;
		y = s;
		z = s;
	}

	Vec3() { x = y = z = 0.0; }
	Vec3(float x, float y, float z) : x(x), y(y), z(z) { }
	Vec3(BlockPos const& pos) : x(float(pos.x)), y(float(pos.y)), z(float(pos.z)) {}
	Vec3(Pos const&);

	bool isNan() const;

	Vec2 xz() const;

	float minComponent() const;
	float maxComponent() const;

	std::string toString() const {
		std::stringstream stm;
		stm << "(" << x << ", " << y << ", " << z << ")";
		return stm.str();
	}

	bool operator==(const Vec3& rhs) const {
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	bool operator!=(const Vec3& rhs) const {
		return !(*this == rhs);
	}

	static Vec3 clamp(Vec3 const&, Vec3 const&, Vec3 const&);
	static Vec3 clampAlongNormal(Vec3 const&, Vec3 const&, Vec3 const&, Vec3 const&, Vec3&);

	static Vec3 directionFromRotation(Vec2 const&);
	static Vec3 directionFromRotation(float, float);
	static Vec3 rotationFromDirection(Vec3 const&);

	static Vec3 ZERO;
	static Vec3 ONE;
	static Vec3 UNIT_X;
	static Vec3 NEG_UNIT_X;
	static Vec3 UNIT_Y;
	static Vec3 NEG_UNIT_Y;
	static Vec3 UNIT_Z;
	static Vec3 NEG_UNIT_Z;
	static Vec3 MAX;
	static Vec3 MIN;

};

inline Vec3 Vec3::ZERO{};