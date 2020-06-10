#include "ENItems.h"

#include "minecraft/ItemRegistry.h"
#include "minecraft/BlockPlanterItem.h"
#include "minecraft/VanillaBlockRegistry.h"

#include "ItemResource.h"
#include "ItemCookedSilkworm.h"
#include "seeds/ItemSeedBase.h"

WeakPtr<ItemResource> ENItems::resources;
WeakPtr<ItemCookedSilkworm> ENItems::cookedSilkworm;

WeakPtr<ItemSeedBase> ENItems::itemSeedSaplings;
std::vector<WeakPtr<ItemSeedBase>> ENItems::itemSeeds;

void ENItems::init() {
	resources = ItemRegistry::registerItem<ItemResource>("itemMaterial", 4000);

	cookedSilkworm = ItemRegistry::registerItem<ItemCookedSilkworm>("silkwormCooked", 4001);

	itemSeedSaplings = ItemRegistry::registerItem<ItemSeedBase>("itemSeed", 4002, **VanillaBlocks::mSapling, true);
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedCactus", 4003, **VanillaBlocks::mCactus));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedSugarcane", 4004, **VanillaBlocks::mReeds));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedCarrot", 4005, **VanillaBlocks::mCarrotCrop));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("itemSeedPotato", 4006, **VanillaBlocks::mPotatoCrop));
}

void ENItems::initCreativeCategories() {
	resources->setCategory(CreativeItemCategory::ITEMS);
	cookedSilkworm->setCategory(CreativeItemCategory::ITEMS);
	itemSeedSaplings->setCategory(CreativeItemCategory::ITEMS);
	for (WeakPtr<ItemSeedBase> item : itemSeeds)
		item->setCategory(CreativeItemCategory::ITEMS);
}

void ENItems::initCreativeItemsCallback() {
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
	resources->setIcon("itemMaterial", 0);
	cookedSilkworm->setIcon("itemCookedSilkworm", 0);
	itemSeedSaplings->setIcon("itemSeed", 0);
	itemSeeds[0]->setIcon("itemSeedCactus", 0);
	itemSeeds[1]->setIcon("itemSeedSugarcane", 0);
	itemSeeds[2]->setIcon("itemSeedCarrot", 0);
	itemSeeds[3]->setIcon("itemSeedPotato", 0);
}