#include "ENBlocks.h"

#include "minecraft/item/BlockItem.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/block/BlockTypeRegistry.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/BlockDefinitionGroup.h"
#include "minecraft/client/BlockGraphics.h"
#include "minecraft/item/Item.h"

#include "BlockBaseFalling.h"

WeakPtr<BlockLegacy> ENBlocks::dust;
WeakPtr<BlockLegacy> ENBlocks::netherrackCrushed;
WeakPtr<BlockLegacy> ENBlocks::endstoneCrushed;

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
}

void ENBlocks::initCreativeBlocks() {
	Item::addCreativeItem(dust->getDefaultState());
	Item::addCreativeItem(netherrackCrushed->getDefaultState());
	Item::addCreativeItem(endstoneCrushed->getDefaultState());
}