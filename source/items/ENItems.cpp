#include "ENItems.h"

#include "minecraft/ItemRegistry.h"

#include "ItemResource.h"

WeakPtr<ItemResource> ENItems::resources;

void ENItems::init() {
	resources = ItemRegistry::registerItem<ItemResource>("itemMaterial", 4000);
}

void ENItems::initCreativeCategories() {
	resources->setCategory(CreativeItemCategory::ITEMS);
}

void ENItems::initCreativeItemsCallback() {
	Item::beginCreativeGroup("itemGroup.name.resources", resources.get(), 1, nullptr);
	for (int i = 1; i < 6; i++)
		Item::addCreativeItem(resources.get(), i);
	Item::endCreativeGroup();
}

void ENItems::initClientData() {
	resources->setIcon("itemMaterial", 0);
}