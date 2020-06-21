#pragma once

class Facing {
public:
    static const int STEP_X[6];
    static const int STEP_Y[6];
    static const int STEP_Z[6];
};

inline const int Facing::STEP_X[6] = { 0, 0, 0, 0, -1, 1 };
inline const int Facing::STEP_Y[6] = { -1, 1, 0, 0, 0, 0 };
inline const int Facing::STEP_Z[6] = { 0, 0, -1, 1, 0, 0 };