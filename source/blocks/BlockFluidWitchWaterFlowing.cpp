#include "BlockFluidWitchWaterFlowing.h"
#include "BlockFluidWitchWaterStill.h"

#include "ENBlocks.h"

#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Level.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/BlockPalette.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/actor/Actor.h"
#include "minecraft/actor/ActorFactory.h"

BlockFluidWitchWaterFlowing::BlockFluidWitchWaterFlowing(const std::string& nameId, int id) : LiquidBlockDynamic(nameId, id, Material::getMaterial(MaterialType::Water)) {
	setDestroyTime(100.0f);
	setLightBlock(2);
	setCategory(CreativeItemCategory::DECORATIONS);
	addState(*VanillaStates::LiquidDepth);
	setAllowsRunes(true);
	addProperty(BlockProperty::Liquid);
	addProperty(BlockProperty::CanBeBuiltOver);
}

Color BlockFluidWitchWaterFlowing::getMapColor(BlockSource&, const BlockPos&) const {
	return {0.125F, 0.0f, 0.322F, 1.0f};
}

void BlockFluidWitchWaterFlowing::entityInside(BlockSource& region, const BlockPos& pos, Actor& entity) const {
	EntityInWitchWater(region, pos, entity);
}

void BlockFluidWitchWaterFlowing::_setStatic(BlockSource& region, const BlockPos& pos, bool usingExtraData) const {
	auto& block = region.getLiquidBlock(pos);
	auto& palette = region.getLevel().getGlobalBlockPalette();
	if (*this == block.getLegacyBlock())
		region.setLiquidBlock(pos, palette.switchBlock(block, *ENBlocks::blockWitchwaterStill->get()), usingExtraData, 2);
}
