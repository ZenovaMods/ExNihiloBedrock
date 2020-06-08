#include "ENItems.h"

#include "minecraft/ItemRegistry.h"

#include "ItemResource.h"
#include "ItemCookedSilkworm.h"

WeakPtr<ItemResource> ENItems::resources;
WeakPtr<ItemCookedSilkworm> ENItems::cookedSilkworm;

void ENItems::init() {
	resources = ItemRegistry::registerItem<ItemResource>("itemMaterial", 4000);

	cookedSilkworm = ItemRegistry::registerItem<ItemCookedSilkworm>("silkwormCooked", 4001);
}

void ENItems::initCreativeCategories() {
	resources->setCategory(CreativeItemCategory::ITEMS);
	cookedSilkworm->setCategory(CreativeItemCategory::ITEMS);
}

void ENItems::initCreativeItemsCallback() {
	Item::beginCreativeGroup("itemGroup.name.resources", resources.get(), 1, nullptr);
	for (int i = 1; i < 6; i++)
		Item::addCreativeItem(resources.get(), i);
	Item::endCreativeGroup();
	Item::addCreativeItem(cookedSilkworm.get(), 0);
}

void ENItems::initClientData() {
	resources->setIcon("itemMaterial", 0);
	cookedSilkworm->setIcon("itemCookedSilkworm", 0);
}