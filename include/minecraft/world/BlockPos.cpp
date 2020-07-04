#include "BlockPos.h"

#include "../util/Facing.h"

BlockPos BlockPos::neighbor(FacingID direction) const {
	return *this + Facing::DIRECTION[direction];
}
