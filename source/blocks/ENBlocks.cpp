#include "ENBlocks.h"

#include "minecraft/BlockItem.h"
#include "minecraft/ItemRegistry.h"
#include "minecraft/BlockTypeRegistry.h"
#include "minecraft/Block.h"
#include "minecraft/BlockGraphics.h"
#include "minecraft/Item.h"

#include "BlockBaseFalling.h"
#include <Zenova.h>

WeakPtr<BlockLegacy> ENBlocks::dust;
WeakPtr<BlockLegacy> ENBlocks::netherrackCrushed;
WeakPtr<BlockLegacy> ENBlocks::endstoneCrushed;

__declspec(noinline)
void ENBlocks::init() {
	dust = BlockTypeRegistry::registerBlock<BlockBaseFalling>("blockDust", 1000)
		.setCategory(CreativeItemCategory::BLOCKS)
		.setDestroyTime(0.7F)
		.createWeakPtr();

	netherrackCrushed = BlockTypeRegistry::registerBlock<BlockBaseFalling>("blockNetherrackCrushed", 1001)
		.setCategory(CreativeItemCategory::BLOCKS)
		.setDestroyTime(0.7F)
		.createWeakPtr();

	endstoneCrushed = BlockTypeRegistry::registerBlock<BlockBaseFalling>("blockEndstoneCrushed", 1002)
		.setCategory(CreativeItemCategory::BLOCKS)
		.setDestroyTime(0.7F)
		.createWeakPtr();

	Zenova::Platform::DebugPause();
	Zenova_Info("pog");
}

__declspec(noinline)
void ENBlocks::initBlockItems() {
	ItemRegistry::registerBlockItem<BlockItem>(dust->getDescriptionId(), *dust.get());
	ItemRegistry::registerBlockItem<BlockItem>(netherrackCrushed->getDescriptionId(), *netherrackCrushed.get());
	ItemRegistry::registerBlockItem<BlockItem>(endstoneCrushed->getDescriptionId(), *endstoneCrushed.get());
}

__declspec(noinline)
void ENBlocks::initGraphics(std::vector<Json::Value>& json) {
	BlockGraphics::registerBlockGraphics(json, "blockDust", BlockShape::BLOCK);
	BlockGraphics::registerBlockGraphics(json, "blockNetherrackCrushed", BlockShape::BLOCK);
	BlockGraphics::registerBlockGraphics(json, "blockEndstoneCrushed", BlockShape::BLOCK);
}

__declspec(noinline)
void ENBlocks::initCreativeBlocksCallback() {
	Item::addCreativeItem(dust->getDefaultState());
	Item::addCreativeItem(netherrackCrushed->getDefaultState());
	Item::addCreativeItem(endstoneCrushed->getDefaultState());
}