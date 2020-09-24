#pragma once

#include <utility>

#include "ResourceLocation.h"

class IsotropicFaceData {
private:
    unsigned int mFaceTextureIsotropic;
    unsigned int mIsotropicFaceEnabled;
};

struct TextureUVCoordinateSet {
private:
    float weight;
    float _u0;
    float _v0;
    float _u1;
    float _v1;
    uint16_t _texSizeW;
    uint16_t _texSizeH;
    ResourceLocation sourceFileLocation;
    IsotropicFaceData mIsotropicFaceData;
};