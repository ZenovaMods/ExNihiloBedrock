#pragma once

#include <string>

#include "../CommonTypes.h"

class ChunkPos;
class Vec3;

class BlockPos {
public:

	int x, y, z;

	BlockPos(int x, int y, int z) : x(x), y(y), z(z) { }
	BlockPos(float x, float y, float z) : x(int(floorf(x))), y(int(floorf(y))), z(int(floorf(z))) {}
	BlockPos(Vec3 const&);
	BlockPos(ChunkPos const&, int);
	BlockPos(BlockPos const& b) : x(b.x), y(b.y), z(b.z) { }

	std::string toString() const;

	BlockPos above() const {
		return { x, y + 1, z };
	}
	BlockPos above(int steps) const {
		return { x, y + steps, z };
	}
	BlockPos below() const {
		return { x, y - 1, z };
	}
	BlockPos below(int steps) const {
		return { x, y - steps, z };
	}
	BlockPos neighbor(FacingID) const;
	BlockPos relative(signed char, int) const;

	Vec3 center() const;


	BlockPos operator*(int s) const {
		return { x * s, y * s, z * s };
	}
	const BlockPos& operator*=(int s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	BlockPos operator/(int s) const {
		return { x / s, y / s, z / s };
	}
	BlockPos operator+(const BlockPos& rhs) const {
		return { x + rhs.x, y + rhs.y, z + rhs.z };
	}
	BlockPos operator+(int s) const {
		return { x + s, y + s, z + s };
	}
	BlockPos operator-(const BlockPos& rhs) const {
		return { x - rhs.x, y - rhs.y, z - rhs.z };
	}
	BlockPos operator-(int s) const {
		return { x - s, y - s, z - s };
	}
	BlockPos operator-() const {
		return { -x, -y, -z };
	}
	const BlockPos& operator+=(const BlockPos& o) {
		x += o.x;
		y += o.y;
		z += o.z;
		return *this;
	}
	const BlockPos& operator-=(const BlockPos& o) {
		x -= o.x;
		y -= o.y;
		z -= o.z;
		return *this;
	}

	static BlockPos MIN;
	static BlockPos MAX;
	static BlockPos ONE;
	static BlockPos ZERO;

};