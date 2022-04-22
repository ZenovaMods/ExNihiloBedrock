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
#include "../blocks/BlockInfestingLeaves.h"

void InfestingLeavesRenderer::render(BaseActorRenderContext& context, BlockActorRenderData& data) {
	ScreenContext& screenContext = context.getScreenContext();
	BlockSource& region = data.mRegion;
	const BlockActorInfestingLeaves& infestingLeaves = (BlockActorInfestingLeaves&)data.mBlockActor;
	Vec3 renderPos = data.mPos;
	BlockPos blockPos = infestingLeaves.getPosition();
	const Block& block = BlockInfestingLeaves::getBlockForLeaf(region.getBlock(blockPos));
	MatrixStack::MatrixStackRef worldMatrix = context.getWorldMatrix().push();
	worldMatrix->translate(renderPos.x - blockPos.x, renderPos.y - blockPos.y, renderPos.z - blockPos.z);
	setupShaderParameters(screenContext, region, infestingLeaves.getPosition(), context.mPartialTicks, context.isIgnoringLightning(), *context.getLightTexture(), Vec2::ONE, {});
	Tessellator& tessellator = context.getTessellator();
	tessellator.addPostTransformOffset((float)-blockPos.x, (float)-blockPos.y, (float)-blockPos.z);
	worldMatrix->translate((float)blockPos.x, (float)blockPos.y, (float)blockPos.z);
	std::array<const mce::ClientTexture*, 2> textures = { mTerrainTexture.getClientTexture(), context.getLightTexture()->getClientTexture() };
	BlockRenderLayer renderLayer = block.getRenderLayer(region, blockPos);
	mce::Mesh mesh = getBlockMesh(mBlockTessellator, tessellator, block, blockPos, renderLayer, infestingLeaves);
	mesh.renderMesh(screenContext.mMeshContext, mRenderLayerMaterials[Zenova::enum_cast(renderLayer)], textures, 0, 0, nullptr);
	tessellator.addPostTransformOffset((float)blockPos.x, (float)blockPos.y, (float)blockPos.z);
}

mce::Mesh InfestingLeavesRenderer::getBlockMesh(BlockTessellator& blockTessellator, Tessellator& tessellator, const Block& block, BlockPos& pos, BlockRenderLayer renderLayer, const BlockActorInfestingLeaves& leafActor) {
	blockTessellator.mUseNormals = false;
	blockTessellator.mBool4 = false;
	blockTessellator.mBool5 = false;
	blockTessellator.setCurrentShape(block.getVisualShape(AABB(), false));
	if (&blockTessellator.mRegion != nullptr)
		blockTessellator.mCache.reset(blockTessellator.mRegion, pos);
	blockTessellator.mRenderLayer = renderLayer;

	tessellator.beginOverride();
	blockTessellator.tessellateInWorld(tessellator, block, pos, nullptr);
	blockTessellator.mBool4 = false;
	blockTessellator.mBool5 = true;
	blockTessellator.mUseNormals = false;
	return tessellator.endOverride("Untagged Tessellator Mesh Override");
}
