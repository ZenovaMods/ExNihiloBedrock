#include "ENBlocks.h"

#include "minecraft/item/BlockItem.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/block/BlockTypeRegistry.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/BlockDefinitionGroup.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/client/BlockGraphics.h"
#include "minecraft/item/Item.h"

#include "BlockBaseFalling.h"
#include "BlockFluidWitchWaterStill.h"
#include "BlockFluidWitchWaterFlowing.h"

WeakPtr<BlockLegacy> ENBlocks::dust;
WeakPtr<BlockLegacy> ENBlocks::netherrackCrushed;
WeakPtr<BlockLegacy> ENBlocks::endstoneCrushed;
WeakPtr<BlockLegacy> ENBlocks::blockWitchwaterStill;
WeakPtr<BlockLegacy> ENBlocks::blockWitchwaterFlowing;

void ENBlocks::init(BlockDefinitionGroup* blockGroup) {
	dust = BlockTypeRegistry::registerBlock<BlockBaseFalling>("exnihilo:blockDust", blockGroup->getNextBlockId())
		.setCategory(CreativeItemCategory::DECORATIONS)
		.setDestroyTime(0.7F)
		.setIsVanillaBlock(false)
		.createWeakPtr();

	netherrackCrushed = BlockTypeRegistry::registerBlock<BlockBaseFalling>("exnihilo:blockNetherrackCrushed", blockGroup->getNextBlockId())
		.setCategory(CreativeItemCategory::DECORATIONS)
		.setDestroyTime(0.7F)
		.setIsVanillaBlock(false)
		.createWeakPtr();

	endstoneCrushed = BlockTypeRegistry::registerBlock<BlockBaseFalling>("exnihilo:blockEndstoneCrushed", blockGroup->getNextBlockId())
		.setCategory(CreativeItemCategory::DECORATIONS)
		.setDestroyTime(0.7F)
		.setIsVanillaBlock(false)
		.createWeakPtr();

	blockWitchwaterStill = BlockTypeRegistry::registerBlock<BlockFluidWitchWaterStill>("exnihilo:witchwater", blockGroup->getNextBlockId())
		.setDestroyTime(100.0F)
		.setLightBlock(2)
		.setCategory(CreativeItemCategory::DECORATIONS)
		.addState(*VanillaStates::LiquidDepth)
		.setAllowsRunes(true)
		.addProperty(BlockProperty::Liquid)
		.addProperty(BlockProperty::CanBeBuiltOver)
		.setIsVanillaBlock(false)
		.createWeakPtr();

	blockWitchwaterFlowing = BlockTypeRegistry::registerBlock<BlockFluidWitchWaterFlowing>("exnihilo:witchwaterFlowing", blockGroup->getNextBlockId())
		.setDestroyTime(100.0F)
		.setLightBlock(2)
		.setCategory(CreativeItemCategory::DECORATIONS)
		.addState(*VanillaStates::LiquidDepth)
		.setAllowsRunes(true)
		.addProperty(BlockProperty::Liquid)
		.addProperty(BlockProperty::CanBeBuiltOver)
		.setIsVanillaBlock(false)
		.createWeakPtr();

	WeakPtr<BlockLegacy> waterBlock = BlockTypeRegistry::lookupByName("minecraft:flowing_water");
	Zenova_Info("{}", waterBlock->getBlockItemId());
}

void ENBlocks::initBlockItems() {
	ItemRegistry::registerBlockItem<BlockItem>(dust->getDescriptionId(), *dust.get());
	ItemRegistry::registerBlockItem<BlockItem>(netherrackCrushed->getDescriptionId(), *netherrackCrushed.get());
	ItemRegistry::registerBlockItem<BlockItem>(endstoneCrushed->getDescriptionId(), *endstoneCrushed.get());
}

void ENBlocks::initGraphics(std::vector<Json::Value>& json) {
	BlockGraphics::registerBlockGraphics(json, "blockDust", BlockShape::BLOCK);
	BlockGraphics::registerBlockGraphics(json, "blockNetherrackCrushed", BlockShape::BLOCK);
	BlockGraphics::registerBlockGraphics(json, "blockEndstoneCrushed", BlockShape::BLOCK);
	BlockGraphics::registerBlockGraphics(json, "witchwater", BlockShape::WATER);
	BlockGraphics::registerBlockGraphics(json, "witchwaterFlowing", BlockShape::WATER);
}

void ENBlocks::initCreativeBlocks() {
	Item::addCreativeItem(dust->getDefaultState());
	Item::addCreativeItem(netherrackCrushed->getDefaultState());
	Item::addCreativeItem(endstoneCrushed->getDefaultState());
}