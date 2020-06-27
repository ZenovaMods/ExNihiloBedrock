#pragma once

#include "LevelListener.h"
#include "../util/SavedData.h"
#include "../CommonTypes.h"

class Level;

typedef int DimensionType;

class Dimension : public LevelListener, public SavedData {
protected:
    Level& mLevel;
    Height mSeaLevel;
    std::unique_ptr<BlockSource> mBlockSource;
    float mMobsPerChunkSurface[7];
    float mMobsPerChunkUnderground[7];
    BrightnessPair mDefaultBrightness;
private:
    std::string mName;
    DimensionType mId;
    bool mUltraWarm;
    bool mHasCeiling;
    bool mHasWeather;
    bool mHasSkylight;
    Brightness mSkyDarken;
    Height mHeight;
    float mBrightnessRamp[16];

public:
    virtual ~Dimension();
    bool isUltraWarm() const {
        return mUltraWarm;
    }
    void setUltraWarm(bool ultraWarm) {
        mUltraWarm = ultraWarm;
    }
};