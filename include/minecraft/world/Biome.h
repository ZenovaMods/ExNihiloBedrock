#pragma once

#include "../util/Color.h"

class BlockPos;
class BlockSource;

class Biome {
public:
    std::string mName;
    int mDebugMapColor;
    int mDebugMapOddColor;
    float mTemperature;
    float mDownfall;
    float mSnowAccumulation;
    float mFoliageSnow;
    float mMinSnowLevel;
    float mMaxSnowLevel;
    float mDepth;
    float mScale;
    Color mWaterColor;
    float mWaterTranparency;
    Color mUnderWaterColor;
    bool mRain;
    int mId;
    float mFogDist;
    char filler[0x68];

    bool canHaveSnowfall(const BlockSource& region, const BlockPos& pos) const {
        return (mMaxSnowLevel > 0.0) && (getTemperature(region, pos) < 0.15F);
    }
    float getDefaultBiomeTemperature() const {
        return mTemperature;
    }
    float getDownfall() const {
        return mDownfall;
    }
    float getTemperature(const BlockSource&, const BlockPos&) const;
    int getFoliageColor(const BlockPos&) const;
    int getBirchFoliageColor(const BlockPos&) const;
    int getEvergreenFoliageColor(const BlockPos&) const;
    int getMapFoliageColor(const BlockPos&) const;
    int getMapBirchFoliageColor(const BlockPos&) const;
    int getMapEvergreenFoliageColor(const BlockPos&) const;
};