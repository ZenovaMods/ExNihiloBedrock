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

public:
    TextureUVCoordinateSet(float, float, float, float, uint16_t, uint16_t, ResourceLocation, float);
    TextureUVCoordinateSet();
    float width() const;
    float height() const;
    float offsetWidth(float, float) const;
    float offsetHeight(float, float) const;
    float offsetWidthPixel(float, float) const;
    float offsetHeightPixel(float, float) const;
    float inverseOffsetWidth(float, float) const;
    float inverseOffsetHeight(float, float) const;
    TextureUVCoordinateSet getFlippedHorizontal() const;
    TextureUVCoordinateSet getFlippedVertically() const;
    TextureUVCoordinateSet offset(float) const;
    TextureUVCoordinateSet subTexture(float, float, int, int) const;
    uint16_t asPixelU0() const;
    uint16_t asPixelV0() const;
    uint16_t asPixelU1() const;
    uint16_t asPixelV1() const;
    uint16_t pixelWidth() const;
    uint16_t pixelHeight() const;
    std::pair<unsigned short, unsigned short> topLeftPixel() const;
    float pixelSizeU() const;
    float pixelSizeV() const;
    size_t hashCode() const;
    bool operator==(const TextureUVCoordinateSet&) const;
    static TextureUVCoordinateSet fromOldSystem(int);
};