#include "InfestingLeavesRenderer.h"

#include <Zenova.h>

#include "minecraft/block/Block.h"
#include "minecraft/client/BaseActorRenderContext.h"
#include "minecraft/client/BlockActorRenderData.h"
#include "minecraft/client/BlockTessellator.h"
#include "minecraft/client/Matrix.h"
#include "minecraft/client/Mesh.h"
#include "minecraft/client/Tessellator.h"
#include "minecraft/util/Vec4.h"
#include "minecraft/util/AABB.h"

#include "BlockActorInfestingLeaves.h"

void InfestingLeavesRenderer::render(BaseActorRenderContext& context, BlockActorRenderData& data) {
	ScreenContext& screenContext = context.getScreenContext();
	BlockSource& region = data.mRegion;
	const BlockActorInfestingLeaves& infestingLeaves = (BlockActorInfestingLeaves&)data.mBlockActor;
	Vec3 renderPos = data.mPos;
	const Block& block = *infestingLeaves.getLeafBlock();
	BlockPos blockPos = infestingLeaves.getPosition();
	MatrixStack::MatrixStackRef worldMatrix = context.getWorldMatrix().push();
	worldMatrix->translate(renderPos.x - blockPos.x, renderPos.y - blockPos.y, renderPos.z - blockPos.z);
	setupShaderParameters(screenContext, region, infestingLeaves.getPosition(), context.mPartialTicks, context.isIgnoringLightning(), *context.getLightTexture(), Vec2::ONE, {});
	Tessellator& tessellator = context.getTessellator();
	tessellator.addPostTransformOffset((float)-blockPos.x, (float)-blockPos.y, (float)-blockPos.z);
	worldMatrix->translate((float)blockPos.x, (float)blockPos.y, (float)blockPos.z);
	std::array<const mce::ClientTexture*, 2> textures = { mTerrainTexture.getClientTexture(), context.getLightTexture()->getClientTexture() };
	BlockRenderLayer renderLayer = block.getLegacyBlock().getRenderLayer(block, region, blockPos);
	mce::Mesh mesh = getBlockMesh(mBlockTessellator, tessellator, block, blockPos, renderLayer, infestingLeaves);
	mesh.renderMesh(screenContext.mMeshContext, mRenderLayerMaterials[enum_cast(renderLayer)], textures, 0, 0, nullptr);
	tessellator.addPostTransformOffset((float)blockPos.x, (float)blockPos.y, (float)blockPos.z);
}

mce::Mesh InfestingLeavesRenderer::getBlockMesh(BlockTessellator& blockTessellator, Tessellator& tessellator, const Block& block, BlockPos& pos, BlockRenderLayer renderLayer, const BlockActorInfestingLeaves& blockActor) {
	blockTessellator.mBool2 = false;
	blockTessellator.mBool4 = false;
	blockTessellator.mBool5 = false;
	blockTessellator.mHasBounds = true;
	blockTessellator.mBounds = block.getVisualShape(AABB(), false);
	Color blockColor;
	if (&blockTessellator.mRegion != nullptr) {
		blockTessellator.mCache.reset(blockTessellator.mRegion, pos);
		blockColor = blockActor.getLeafColor(blockTessellator.mRegion);
	}
	else {
		blockColor = Color::WHITE;
	}
	blockTessellator.mRenderLayer = renderLayer;

	tessellator.beginOverride();
	tessellator.color(blockColor);
	blockTessellator.tessellateInWorld(tessellator, block, pos, nullptr);
	blockTessellator.mBool4 = true;
	blockTessellator.mBool5 = false;
	blockTessellator.mBool2 = false;
	return tessellator.endOverride("Untagged Tessellator Mesh Override");
}
