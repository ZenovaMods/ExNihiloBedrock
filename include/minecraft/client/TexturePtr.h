#pragma once

#include <memory>

#include "ResourceLocation.h"
#include "../util/Vec2.h"
#include "../CommonTypes.h"

class BedrockTextureData {
	char filler[0x68];
};

struct BedrockTexture {
	std::shared_ptr<BedrockTextureData> mTextureData;
};

namespace mce {
	class ClientTexture {
	public:
		std::shared_ptr<BedrockTextureData> mTextureData;
	};

	class TexturePtr {
	public:
		std::shared_ptr<BedrockTextureData> mClientTexture;
		ResourceLocation mTextureLocation;

		~TexturePtr();
		ClientTexture* getClientTexture() const;
	};
}

class LightTexture {
public:
	char filler[0x58];
	mce::ClientTexture* mClientTexture;

	mce::ClientTexture* getClientTexture() const { return mClientTexture; }

	static Vec2 brightnessToUV(BrightnessPair);
};