#include "ENBlocks.h"

#include "minecraft/item/BlockItem.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/client/BlockGraphics.h"
#include "minecraft/item/Item.h"

#include "FluidRegistry.h"
#include "BlockRegistry.h"
#include "BlockBaseFalling.h"
#include "BlockFluidWitchWaterStill.h"
#include "BlockFluidWitchWaterFlowing.h"

WeakPtr<BlockLegacy>* ENBlocks::dust;
WeakPtr<BlockLegacy>* ENBlocks::netherrackCrushed;
WeakPtr<BlockLegacy>* ENBlocks::endstoneCrushed;
WeakPtr<BlockLegacy>* ENBlocks::andesiteCrushed;
WeakPtr<BlockLegacy>* ENBlocks::dioriteCrushed;
WeakPtr<BlockLegacy>* ENBlocks::graniteCrushed;
WeakPtr<BlockLegacy>* ENBlocks::blockWitchwaterStill;
WeakPtr<BlockLegacy>* ENBlocks::blockWitchwaterFlowing;

void ENBlocks::init() {
	dust = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockDust", BlockShape::BLOCK);
	netherrackCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockNetherrackCrushed", BlockShape::BLOCK);
	endstoneCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockEndstoneCrushed", BlockShape::BLOCK);
	andesiteCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockAndesiteCrushed", BlockShape::BLOCK);
	dioriteCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockDioriteCrushed", BlockShape::BLOCK);
	graniteCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockGraniteCrushed", BlockShape::BLOCK);
	blockWitchwaterStill = Zenova::BlockRegistry::registerBlock<BlockFluidWitchWaterStill>("witchwater", BlockShape::WATER);
	blockWitchwaterFlowing = Zenova::BlockRegistry::registerBlock<BlockFluidWitchWaterFlowing>("witchwaterFlowing", BlockShape::WATER);

	FluidRegistry::registerFluid("witchwater", "bucket_witchwater", 0, blockWitchwaterStill, blockWitchwaterFlowing);
}

void ENBlocks::initBlockItems() {
	ItemRegistry::registerBlockItem<BlockItem>(dust->get()->getDescriptionId(), *dust->get());
	ItemRegistry::registerBlockItem<BlockItem>(netherrackCrushed->get()->getDescriptionId(), *netherrackCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(endstoneCrushed->get()->getDescriptionId(), *endstoneCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(andesiteCrushed->get()->getDescriptionId(), *andesiteCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(dioriteCrushed->get()->getDescriptionId(), *dioriteCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(graniteCrushed->get()->getDescriptionId(), *graniteCrushed->get());
}

void ENBlocks::initCreativeBlocks() {
	Item::addCreativeItem(dust->get()->getDefaultState());
	Item::addCreativeItem(netherrackCrushed->get()->getDefaultState());
	Item::addCreativeItem(endstoneCrushed->get()->getDefaultState());
	Item::addCreativeItem(andesiteCrushed->get()->getDefaultState());
	Item::addCreativeItem(dioriteCrushed->get()->getDefaultState());
	Item::addCreativeItem(graniteCrushed->get()->getDefaultState());
}