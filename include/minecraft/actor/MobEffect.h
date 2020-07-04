#pragma once

#include "../util/Color.h"

#include <memory>

class MobEffect {
protected:
    const unsigned int mId;
    bool mIsHarmful;
    Color mColor;
    std::string mDescriptionId;
    int mIcon;
    float mDurationModifier;
    bool mIsDisabled;
    std::string mResourceName;
    std::string mIconName;
    bool mEffectVisible;
    char filler[0x78];

public:
    static MobEffect* getByName(const std::string&);
    virtual ~MobEffect();
    unsigned int getId() const {
        return mId;
    }
};