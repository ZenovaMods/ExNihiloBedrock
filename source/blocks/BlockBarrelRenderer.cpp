#include "BlockBarrelRenderer.h"

bool BlockBarrelRenderer::renderInWorld(BlockTessellator* blockTessellator, Tessellator& tessellator, const Block& block, const BlockPos& pos) {
	BlockOccluder* bo;

	blockTessellator->setCurrentShape({ 0.0625f, 0.0625f, 0.0625f, 0.9375f, 1.0f, 0.125f });
	bo = new BlockOccluder(blockTessellator->mCache, block, pos, blockTessellator->getCurrentShape(), { Facing::UP, Facing::NORTH, Facing::SOUTH }, blockTessellator->mNoLighting);
	blockTessellator->tessellateBlockInWorldWithAmbienceOcclusion(tessellator, block, pos, Color::WHITE, bo, 0);

	blockTessellator->setCurrentShape({ 0.0625f, 0.0625f, 0.0625f, 0.125f, 1.0f, 0.9375f });
	bo = new BlockOccluder(blockTessellator->mCache, block, pos, blockTessellator->getCurrentShape(), { Facing::UP, Facing::WEST, Facing::EAST }, blockTessellator->mNoLighting);
	blockTessellator->tessellateBlockInWorldWithAmbienceOcclusion(tessellator, block, pos, Color::WHITE, bo, 0);

	blockTessellator->setCurrentShape({ 0.0625f, 0.0625f, 0.875f, 0.9375f, 1.0f, 0.9375f });
	bo = new BlockOccluder(blockTessellator->mCache, block, pos, blockTessellator->getCurrentShape(), { Facing::UP, Facing::NORTH, Facing::SOUTH }, blockTessellator->mNoLighting);
	blockTessellator->tessellateBlockInWorldWithAmbienceOcclusion(tessellator, block, pos, Color::WHITE, bo, 0);

	blockTessellator->setCurrentShape({ 0.875f, 0.0625f, 0.0625f, 0.9375f, 1.0f, 0.9375f });
	bo = new BlockOccluder(blockTessellator->mCache, block, pos, blockTessellator->getCurrentShape(), { Facing::UP, Facing::WEST, Facing::EAST }, blockTessellator->mNoLighting);
	blockTessellator->tessellateBlockInWorldWithAmbienceOcclusion(tessellator, block, pos, Color::WHITE, bo, 0);

	blockTessellator->setCurrentShape({ 0.0625f, 0.0f, 0.0625f, 0.9375f, 0.0625f, 0.9375f });
	bo = new BlockOccluder(blockTessellator->mCache, block, pos, blockTessellator->getCurrentShape(), { Facing::UP, Facing::DOWN, Facing::NORTH, Facing::SOUTH, Facing::WEST, Facing::EAST }, blockTessellator->mNoLighting);
	blockTessellator->tessellateBlockInWorldWithAmbienceOcclusion(tessellator, block, pos, Color::WHITE, bo, 0);

	return true;
}
