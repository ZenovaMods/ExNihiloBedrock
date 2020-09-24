#pragma once

#include "Facing.h"

class Direction {
public:
    enum class Type : unsigned char {
        SOUTH,
        WEST,
        NORTH,
        EAST,
        UNDEFINED = 255
    };

    static const FacingID DIRECTION_FACING[4];
    static const Type FACING_DIRECTION[6];
    static const Type DIRECTION_OPPOSITE[4];
    static const FacingID RELATIVE_DIRECTION_FACING[4][6];
    static const Type DIRECTION_CLOCKWISE[4];
    static const Type DIRECTION_COUNTER_CLOCKWISE[4];
    static const int STEP_X[4];
    static const int STEP_Z[4];

    static Type getDirection(float, float);
    static Type getDirection(int, int, int, int);
};

inline const FacingID Direction::DIRECTION_FACING[4] = { 3, 4, 2, 5 };
inline const Direction::Type Direction::FACING_DIRECTION[6] = { Direction::Type::UNDEFINED, Direction::Type::UNDEFINED, Direction::Type::NORTH, Direction::Type::SOUTH, Direction::Type::EAST, Direction::Type::WEST };
inline const Direction::Type Direction::DIRECTION_OPPOSITE[4] = { Direction::Type::NORTH, Direction::Type::EAST, Direction::Type::SOUTH, Direction::Type::WEST };
inline const FacingID Direction::RELATIVE_DIRECTION_FACING[4][6] = { { 0, 1, 3, 2, 5, 4 }, { 0, 1, 5, 4, 2, 3 }, { 0, 1, 2, 3, 4, 5 }, { 0, 1, 4, 5, 3, 2 } };
inline const Direction::Type Direction::DIRECTION_CLOCKWISE[4] = { Direction::Type::WEST, Direction::Type::NORTH, Direction::Type::EAST, Direction::Type::SOUTH };
inline const Direction::Type Direction::DIRECTION_COUNTER_CLOCKWISE[4] = { Direction::Type::EAST, Direction::Type::SOUTH, Direction::Type::WEST, Direction::Type::NORTH };
inline const int Direction::STEP_X[4] = { 0, -1, 0, 1 };
inline const int Direction::STEP_Z[4] = { 1, 0, -1, 0 };