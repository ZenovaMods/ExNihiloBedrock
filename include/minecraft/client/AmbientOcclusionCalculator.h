#pragma once

#include "../util/Color.h"
#include "../CommonTypes.h"

class Block;
class BlockPos;
class BlockTessellatorCache;

class AmbientOcclusionCalculator {
public:
    bool mTintSides;
    bool mSeasons;
    bool mTouchEdge;
    float mValues[6];
    BlockTessellatorCache& mCache;
    const BlockPos& mPos;
    const Block& mBlock;
    Color mBaseColor;
    BrightnessPair* mLightTexturePositions;
    Color* mOutputColors;

    AmbientOcclusionCalculator(const BlockPos&, const Block&, BlockTessellatorCache&);
    void calculate(FacingID);
    void setTintSides(bool tintSides) { mTintSides = tintSides; }
    void setTouchEdge(bool touchEdge) { mTouchEdge = touchEdge; }
    void setSeasons(bool seasons) { mSeasons = seasons; }
    void setBaseColor(const Color& baseColor) { mBaseColor = baseColor; }
    void setOutputColors(Color* outputColors) { mOutputColors = outputColors; }
    void setOutputLightTexturePositions(BrightnessPair* positions) { mLightTexturePositions = positions; }
};