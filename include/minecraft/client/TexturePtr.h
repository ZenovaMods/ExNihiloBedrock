#pragma once

#include <memory>

#include "ResourceLocation.h"

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
};