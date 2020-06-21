#pragma once

#include <cstdint>
#include <utility>
#include <string>

class ResourceLocation;

enum class ResourceFileSystem {
    InUserPackage,
    InAppPackage,
    RawPath,
    InSettingDir,
    InExternalDir,
    InServerPackage,
    InDataDir,
    InUserDir,
    InWorldDir
};

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
    char sourceFileLocation[0x38];
    IsotropicFaceData mIsotropicFaceData;
};