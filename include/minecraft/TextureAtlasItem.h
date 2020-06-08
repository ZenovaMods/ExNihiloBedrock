#pragma once

#include <string>
#include <vector>

#include "TextureUVCoordinateSet.h"

class TextureAtlasItem {
protected:
    std::string mName;
    int mParsedNodeIndex;
    std::vector<std::vector<TextureUVCoordinateSet>> mTextureUVs;

public:
    TextureAtlasItem() = default;
    TextureAtlasItem(const TextureAtlasItem&) = default;
    TextureAtlasItem& operator=(const TextureAtlasItem&) = default;
};