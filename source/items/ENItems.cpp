#include "ENItems.h"

#include "minecraft/ItemRegistry.h"
#include "minecraft/BlockPlanterItem.h"
#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/VanillaItemTiers.h"

#include "ItemResource.h"
#include "ItemCookedSilkworm.h"
#include "seeds/ItemSeedBase.h"
#include "tools/CrookBase.h"
#include "tools/HammerBase.h"

WeakPtr<HammerBase> ENItems::hammerWood;
WeakPtr<HammerBase> ENItems::hammerStone;
WeakPtr<HammerBase> ENItems::hammerIron;
WeakPtr<HammerBase> ENItems::hammerDiamond;
WeakPtr<HammerBase> ENItems::hammerGold;

WeakPtr<CrookBase> ENItems::crookWood;
WeakPtr<CrookBase> ENItems::crookBone;

WeakPtr<ItemResource> ENItems::resources;
WeakPtr<ItemCookedSilkworm> ENItems::cookedSilkworm;

WeakPtr<ItemSeedBase> ENItems::itemSeedSaplings;
std::vector<WeakPtr<ItemSeedBase>> ENItems::itemSeeds;

void ENItems::init() {
	hammerWood = ItemRegistry::registerItem<HammerBase>("hammerWood", 4000, 64, *VanillaItemTiers::WOOD);
	hammerStone = ItemRegistry::registerItem<HammerBase>("hammerStone", 4001, 128, *VanillaItemTiers::STONE);
	hammerIron = ItemRegistry::registerItem<HammerBase>("hammerIron", 4002, 512, *VanillaItemTiers::IRON);
	hammerDiamond = ItemRegistry::registerItem<HammerBase>("hammerDiamond", 4003, 4096, *VanillaItemTiers::DIAMOND);
	hammerGold = ItemRegistry::registerItem<HammerBase>("hammerGold", 4004, 64, *VanillaItemTiers::GOLD);

	crookWood = ItemRegistry::registerItem<CrookBase>("crookWood", 4005, 64);
	crookBone = ItemRegistry::registerItem<CrookBase>("crookBone", 4006, 256);

	resources = ItemRegistry::registerItem<ItemResource>("itemMaterial", 4007);

	cookedSilkworm = ItemRegistry::registerItem<ItemCookedSilkworm>("silkwormCooked", 4008);

	itemSeedSaplings = ItemRegistry::registerItem<ItemSeedBase>("itemSeed", 4009, **VanillaBlocks::mSapling, true);
	itemSeeds.clear();
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedCactus", 4010, **VanillaBlocks::mCactus));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedSugarcane", 4011, **VanillaBlocks::mReeds));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedCarrot", 4012, **VanillaBlocks::mCarrotCrop));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedPotato", 4013, **VanillaBlocks::mPotatoCrop));
}

void ENItems::initCreativeCategories() {
	hammerWood->setCategory(CreativeItemCategory::TOOLS);
	hammerStone->setCategory(CreativeItemCategory::TOOLS);
	hammerIron->setCategory(CreativeItemCategory::TOOLS);
	hammerDiamond->setCategory(CreativeItemCategory::TOOLS);
	hammerGold->setCategory(CreativeItemCategory::TOOLS);
	crookWood->setCategory(CreativeItemCategory::TOOLS);
	crookBone->setCategory(CreativeItemCategory::TOOLS);
	resources->setCategory(CreativeItemCategory::ITEMS);
	cookedSilkworm->setCategory(CreativeItemCategory::ITEMS);
	itemSeedSaplings->setCategory(CreativeItemCategory::ITEMS);
	for (WeakPtr<ItemSeedBase> item : itemSeeds)
		item->setCategory(CreativeItemCategory::ITEMS);
}

void ENItems::initCreativeItemsCallback() {
	Item::beginCreativeGroup("itemGroup.name.hammers", hammerWood.get(), 1, nullptr);
	Item::addCreativeItem(hammerWood.get(), 0);
	Item::addCreativeItem(hammerStone.get(), 0);
	Item::addCreativeItem(hammerIron.get(), 0);
	Item::addCreativeItem(hammerDiamond.get(), 0);
	Item::addCreativeItem(hammerGold.get(), 0);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.crooks", crookWood.get(), 1, nullptr);
	Item::addCreativeItem(crookWood.get(), 0);
	Item::addCreativeItem(crookBone.get(), 0);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.resources", resources.get(), 1, nullptr);
	for (int i = 1; i < 6; i++)
		Item::addCreativeItem(resources.get(), i);
	Item::addCreativeItem(cookedSilkworm.get(), 0);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.seeds", itemSeedSaplings.get(), 0, nullptr);
	for (int i = 0; i < 6; i++)
		Item::addCreativeItem(itemSeedSaplings.get(), i);
	for (WeakPtr<ItemSeedBase> item : itemSeeds)
		Item::addCreativeItem(item.get(), 0);
	Item::endCreativeGroup();
}

void ENItems::initClientData() {
	hammerWood->setIcon("itemHammer", 0);
	hammerStone->setIcon("itemHammer", 1);
	hammerIron->setIcon("itemHammer", 2);
	hammerDiamond->setIcon("itemHammer", 3);
	hammerGold->setIcon("itemHammer", 4);
	crookWood->setIcon("itemCrook", 0);
	crookBone->setIcon("itemCrook", 1);
	resources->setIcon("itemMaterial", 0);
	cookedSilkworm->setIcon("itemCookedSilkworm", 0);
	itemSeedSaplings->setIcon("itemSeed", 0);
	itemSeeds[0]->setIcon("itemSeed", 6);
	itemSeeds[1]->setIcon("itemSeed", 7);
	itemSeeds[2]->setIcon("itemSeed", 8);
	itemSeeds[3]->setIcon("itemSeed", 9);
}