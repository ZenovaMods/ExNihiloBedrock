#pragma once

#include "MobEffect.h"

class MobEffectInstance {
    unsigned int mId = 0;
    int mDuration = 0;
    int mDurationEasy = -1;
    int mDurationNormal = -1;
    int mDurationHard = -1;
    int mAmplifier = 0;
    bool mDisplayOnScreenTextureAnimation = false;
    bool mAmbient = false;
    bool mNoCounter = false;
    bool mEffectVisible = false;

public:
    MobEffectInstance() = default;
    MobEffectInstance(unsigned int id) : MobEffectInstance(id, 0) {}
    MobEffectInstance(unsigned int id, int duration) : MobEffectInstance(id, duration, 0) {}
    MobEffectInstance(unsigned int id, int duration, int amplifier) : MobEffectInstance(id, duration, amplifier, false, false, false) {}
    MobEffectInstance(unsigned int id, int duration, int amplifier, int durationEasy, int durationNormal, int durationHard, bool ambient, bool effectVisible, bool displayAnimation);
    MobEffectInstance(unsigned int id, int duration, int amplifier, bool ambient, bool effectVisible, bool displayAnimation) : MobEffectInstance(id, duration, amplifier, -1, -1, -1, ambient, effectVisible, displayAnimation) {}
};