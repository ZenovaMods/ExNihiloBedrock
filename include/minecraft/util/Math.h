#pragma once

namespace mce {
    class Math {
    public:
        static int clamp(int v, int low, int high) {
            if (v > high)
                return high;
            if (v <= low)
                return low;
            return v;
        }
        static float clamp(float v, float low, float high) {
            if (v > high)
                return high;
            if (v <= low)
                return low;
            return v;
        }
    };
}