#include "ENBlocks.h"

#include "minecraft/item/BlockItem.h"
#include "minecraft/item/AuxDataBlockItem.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/item/Item.h"
#include "minecraft/block/LeafType.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/client/BlockGraphics.h"

#include "FluidRegistry.h"
#include "BlockRegistry.h"
#include "BlockBarrel.h"
#include "BlockBaseFalling.h"
#include "BlockInfestedLeaves.h"
#include "BlockInfestingLeaves.h"
#include "BlockFluidWitchWaterStill.h"
#include "BlockFluidWitchWaterFlowing.h"
#include "../blockactors/BlockActorRegistry.h"
#include "BlockBarrelRenderer.h"

WeakPtr<BlockLegacy>* ENBlocks::dust;
WeakPtr<BlockLegacy>* ENBlocks::netherrackCrushed;
WeakPtr<BlockLegacy>* ENBlocks::endstoneCrushed;
WeakPtr<BlockLegacy>* ENBlocks::andesiteCrushed;
WeakPtr<BlockLegacy>* ENBlocks::dioriteCrushed;
WeakPtr<BlockLegacy>* ENBlocks::graniteCrushed;
WeakPtr<BlockLegacy>* ENBlocks::barrelWood;
WeakPtr<BlockLegacy>* ENBlocks::barrelStone;
WeakPtr<BlockLegacy>* ENBlocks::infestingLeaves;
WeakPtr<BlockLegacy>* ENBlocks::infestingLeaves2;
WeakPtr<BlockLegacy>* ENBlocks::infestedLeaves;
WeakPtr<BlockLegacy>* ENBlocks::infestedLeaves2;
WeakPtr<BlockLegacy>* ENBlocks::blockWitchwaterStill;
WeakPtr<BlockLegacy>* ENBlocks::blockWitchwaterFlowing;

void ENBlocks::init() {
	dust = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockDust", BlockShape::BLOCK);
	netherrackCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockNetherrackCrushed", BlockShape::BLOCK);
	endstoneCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockEndstoneCrushed", BlockShape::BLOCK);
	andesiteCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockAndesiteCrushed", BlockShape::BLOCK);
	dioriteCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockDioriteCrushed", BlockShape::BLOCK);
	graniteCrushed = Zenova::BlockRegistry::registerBlock<BlockBaseFalling>("blockGraniteCrushed", BlockShape::BLOCK);

	barrelWood = Zenova::BlockRegistry::registerBlock<BlockBarrel>("blockBarrel0", BlockShape::BARREL, 0, MaterialType::Wood);
	barrelStone = Zenova::BlockRegistry::registerBlock<BlockBarrel>("blockBarrel1", BlockShape::BARREL, 1, MaterialType::Stone);

	infestingLeaves = Zenova::BlockRegistry::registerBlock<BlockInfestingLeavesOld>("blockInfestingLeaves", BlockShape::INVISIBLE);
	infestingLeaves2 = Zenova::BlockRegistry::registerBlock<BlockInfestingLeavesNew>("blockInfestingLeaves2", BlockShape::INVISIBLE);
	infestedLeaves = Zenova::BlockRegistry::registerBlock<BlockInfestedLeavesOld>("blockInfestedLeaves", BlockShape::BLOCK);
	infestedLeaves2 = Zenova::BlockRegistry::registerBlock<BlockInfestedLeavesNew>("blockInfestedLeaves2", BlockShape::BLOCK);
	blockWitchwaterStill = Zenova::BlockRegistry::registerBlock<BlockFluidWitchWaterStill>("witchwater", BlockShape::WATER);
	blockWitchwaterFlowing = Zenova::BlockRegistry::registerBlock<BlockFluidWitchWaterFlowing>("witchwaterFlowing", BlockShape::WATER);

	FluidRegistry::registerFluid("witchwater", "bucket_witchwater", 0, blockWitchwaterStill, blockWitchwaterFlowing);
	Zenova::BlockActorRegistry::registerBlockActor("InfestingLeaves", BlockActorType::InfestingLeaves, infestingLeaves);
	Zenova::BlockActorRegistry::registerBlockActor("InfestedLeaves", BlockActorType::InfestedLeaves, infestedLeaves);

	Zenova::BlockTessellatorRegistry::registerBlockRenderer(new BlockBarrelRenderer(), BlockShape::BARREL);
}

void ENBlocks::initBlockItems() {
	ItemRegistry::registerBlockItem<BlockItem>(dust->get()->getDescriptionId(), *dust->get());
	ItemRegistry::registerBlockItem<BlockItem>(netherrackCrushed->get()->getDescriptionId(), *netherrackCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(endstoneCrushed->get()->getDescriptionId(), *endstoneCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(andesiteCrushed->get()->getDescriptionId(), *andesiteCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(dioriteCrushed->get()->getDescriptionId(), *dioriteCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(graniteCrushed->get()->getDescriptionId(), *graniteCrushed->get());
	ItemRegistry::registerBlockItem<BlockItem>(barrelWood->get()->getDescriptionId(), *barrelWood->get());
	ItemRegistry::registerBlockItem<BlockItem>(barrelStone->get()->getDescriptionId(), *barrelStone->get());
	ItemRegistry::registerBlockItem<AuxDataBlockItem>(infestedLeaves->get()->getDescriptionId(), *infestedLeaves->get(), &infestedLeaves->get()->getDefaultState());
	ItemRegistry::registerBlockItem<AuxDataBlockItem>(infestedLeaves2->get()->getDescriptionId(), *infestedLeaves2->get(), &infestedLeaves2->get()->getDefaultState());
}

void ENBlocks::initCreativeBlocks() {
	Item::beginCreativeGroup("itemGroup.name.crushedBlocks", &dust->get()->getDefaultState(), nullptr);
	Item::addCreativeItem(dust->get()->getDefaultState());
	Item::addCreativeItem(netherrackCrushed->get()->getDefaultState());
	Item::addCreativeItem(endstoneCrushed->get()->getDefaultState());
	Item::addCreativeItem(andesiteCrushed->get()->getDefaultState());
	Item::addCreativeItem(dioriteCrushed->get()->getDefaultState());
	Item::addCreativeItem(graniteCrushed->get()->getDefaultState());
	Item::endCreativeGroup();

	Item::addCreativeItem(barrelWood->get()->getDefaultState());
	Item::addCreativeItem(barrelStone->get()->getDefaultState());

	Item::beginCreativeGroup("itemGroup.name.infestedLeaves", &infestedLeaves->get()->getDefaultState(), nullptr);
	Block& leaves = infestedLeaves->get()->getDefaultState();
	for (int variant = 0; variant < Zenova::enum_cast(OldLeafType::_count); variant++)
		Item::addCreativeItem(*leaves.setState<int>(VanillaStates::OldLeafType, variant));
	Block& leaves2 = infestedLeaves2->get()->getDefaultState();
	for (int variant = 0; variant < Zenova::enum_cast(NewLeafType::_count); variant++)
		Item::addCreativeItem(*leaves2.setState<int>(VanillaStates::NewLeafType, variant));
	Item::endCreativeGroup();
}