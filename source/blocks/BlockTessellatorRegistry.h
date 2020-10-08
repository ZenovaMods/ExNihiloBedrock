#pragma once

#include "minecraft/client/AmbientOcclusionCalculator.h"
#include "minecraft/client/BlockGraphics.h"
#include "minecraft/client/BlockTessellator.h"
#include "minecraft/client/Tessellator.h"
#include "minecraft/client/TexturePtr.h"

namespace Zenova {
	class BlockRenderer {
	public:
		BlockRenderer() = default;
		virtual bool renderInWorld(BlockTessellator*, Tessellator&, const Block&, const BlockPos&) = 0;
	};

	class BlockTessellatorRegistry {
	public:
		static std::unordered_map<BlockShape, BlockRenderer*> rendererMap;

		static bool tessellateInWorld(BlockTessellator* blockTessellator, Tessellator& tessellator, const Block& block, const BlockPos& pos) {
			BlockShape blockShape = BlockGraphics::getForBlock(block)->getBlockShape();

			auto renderer = rendererMap.find(blockShape);
			if (renderer == rendererMap.end())
				return false;

			setupTessellator(blockTessellator, tessellator, block, pos);
			renderer->second->renderInWorld(blockTessellator, tessellator, block, pos);

			if (!blockTessellator->mNoExtraData && block.canHaveExtraData())
				blockTessellator->tessellateExtraDataInWorld(tessellator, block, pos);
			blockTessellator->unsetCurrentShape();
			blockTessellator->reset();
			return true;
		}

		static void setupTessellator(BlockTessellator* blockTessellator, Tessellator& tessellator, const Block& block, const BlockPos& pos) {
			if (!blockTessellator->mNoLighting)
				tessellator._tex(LightTexture::brightnessToUV(blockTessellator->getLightColor(pos)), 1);
			blockTessellator->mPos = pos;
			blockTessellator->mBlock = &block;
		}

		static void registerBlockRenderer(BlockRenderer* renderer, BlockShape blockShape) {
			rendererMap[blockShape] = renderer;
		}
	};

	inline std::unordered_map<BlockShape, BlockRenderer*> BlockTessellatorRegistry::rendererMap{};
}