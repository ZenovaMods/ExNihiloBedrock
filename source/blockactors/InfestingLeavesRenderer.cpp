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

#include "BlockActorInfestingLeaves.h"

void InfestingLeavesRenderer::render(BaseActorRenderContext& context, BlockActorRenderData& data) {
	Zenova::Platform::DebugPause();
	Zenova_Info("&blockActor = {}", (void*)&data.mBlockActor);
	Zenova_Info("&blockActor.leafBlock = {}", (void*)((BlockActorInfestingLeaves&)data.mBlockActor).getLeafBlock());
	Zenova_Info("&leafBlock.mData = {}", ((BlockActorInfestingLeaves&)data.mBlockActor).getLeafBlock()->getDataDEPRECATED());
	/*ScreenContext& screenContext = context.getScreenContext();
	BlockSource& region = data.mRegion;
	const BlockActorInfestingLeaves& infestingLeaves = (BlockActorInfestingLeaves&)data.mBlockActor;
	Vec3 renderPos = data.mPos;
	const Block& block = *infestingLeaves.getLeafBlock();
	BlockPos blockPos = infestingLeaves.getPosition();
	MatrixStack::MatrixStackRef worldMatrix = context.getWorldMatrix().push();
	worldMatrix->translate(renderPos.x - blockPos.x, renderPos.y - blockPos.y, renderPos.z - blockPos.z);
	worldMatrix->translate(0.0F, infestingLeaves.getProgress(), 0.0F);
	setupShaderParameters(screenContext, region, infestingLeaves.getPosition(), context.mPartialTicks, context.isIgnoringLightning(), *context.getLightTexture(), Vec2::ONE, {});
	Tessellator& tessellator = context.getTessellator();
	tessellator.addPostTransformOffset((float)-blockPos.x, (float)-blockPos.y, (float)-blockPos.z);
	worldMatrix->translate((float)blockPos.x, (float)blockPos.y, (float)blockPos.z);
	std::array<const mce::ClientTexture*, 2> textures = { mTerrainTexture.getClientTexture(), context.getLightTexture()->getClientTexture() };
	BlockRenderLayer renderLayer = block.getLegacyBlock().getRenderLayer(block, region, blockPos);
	mce::Mesh& mesh = mBlockTessellator.getMeshForBlockInWorld(tessellator, block, blockPos, renderLayer, &infestingLeaves, false);
	mesh.renderMesh(screenContext.mMeshContext, mRenderLayerMaterials[enum_cast(renderLayer)], textures, 0, 0, nullptr);
	tessellator.addPostTransformOffset((float)blockPos.x, (float)blockPos.y, (float)blockPos.z);*/
}