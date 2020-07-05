#include "BlockPos.h"

#include "../util/Facing.h"
#include "../util/Vec3.h"

BlockPos::BlockPos(Vec3 const& v) : BlockPos(v.x, v.y, v.z) {}

BlockPos BlockPos::neighbor(FacingID direction) const {
	return *this + Facing::DIRECTION[direction];
}
