#include "ENItems.h"

#include <Zenova.h>

#include "minecraft/item/ItemRegistry.h"
#include "minecraft/item/BlockPlanterItem.h"
#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/item/VanillaItemTiers.h"
#include "minecraft/item/ItemStack.h"

#include "UniversalBucket.h"
#include "../blocks/FluidRegistry.h"
#include "ItemResource.h"
#include "ItemPebble.h"
#include "ItemDoll.h"
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
WeakPtr<ItemPebble> ENItems::pebbles;

WeakPtr<ItemDoll> ENItems::dolls;

WeakPtr<ItemSeedBase> ENItems::itemSeedSaplings;
std::vector<WeakPtr<ItemSeedBase>> ENItems::itemSeeds;

WeakPtr<UniversalBucket> ENItems::universalBucket;

void ENItems::init() {
	hammerWood = ItemRegistry::registerItem<HammerBase>("exnihilo:hammerWood", ItemRegistry::getMaxItemID(), 64, *VanillaItemTiers::WOOD);
	hammerStone = ItemRegistry::registerItem<HammerBase>("exnihilo:hammerStone", ItemRegistry::getMaxItemID(), 128, *VanillaItemTiers::STONE);
	hammerIron = ItemRegistry::registerItem<HammerBase>("exnihilo:hammerIron", ItemRegistry::getMaxItemID(), 512, *VanillaItemTiers::IRON);
	hammerDiamond = ItemRegistry::registerItem<HammerBase>("exnihilo:hammerDiamond", ItemRegistry::getMaxItemID(), ItemRegistry::getMaxItemID(), *VanillaItemTiers::DIAMOND);
	hammerGold = ItemRegistry::registerItem<HammerBase>("exnihilo:hammerGold", ItemRegistry::getMaxItemID(), 64, *VanillaItemTiers::GOLD);

	crookWood = ItemRegistry::registerItem<CrookBase>("exnihilo:crookWood", ItemRegistry::getMaxItemID(), 64);
	crookBone = ItemRegistry::registerItem<CrookBase>("exnihilo:crookBone", ItemRegistry::getMaxItemID(), 256);

	resources = ItemRegistry::registerItem<ItemResource>("exnihilo:itemMaterial", ItemRegistry::getMaxItemID());

	cookedSilkworm = ItemRegistry::registerItem<ItemCookedSilkworm>("exnihilo:silkwormCooked", ItemRegistry::getMaxItemID());
	pebbles = ItemRegistry::registerItem<ItemPebble>("exnihilo:pebble", ItemRegistry::getMaxItemID());

	dolls = ItemRegistry::registerItem<ItemDoll>("exnihilo:itemDoll", ItemRegistry::getMaxItemID());

	itemSeedSaplings = ItemRegistry::registerItem<ItemSeedBase>("exnihilo:itemSeed", ItemRegistry::getMaxItemID(), **VanillaBlocks::mSapling, true);
	itemSeeds.clear();
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("exnihilo:itemSeedCactus", ItemRegistry::getMaxItemID(), **VanillaBlocks::mCactus));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("exnihilo:itemSeedSugarcane", ItemRegistry::getMaxItemID(), **VanillaBlocks::mReeds));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("exnihilo:itemSeedCarrot", ItemRegistry::getMaxItemID(), **VanillaBlocks::mCarrotCrop));
	itemSeeds.push_back(ItemRegistry::registerItem<ItemSeedBase>("exnihilo:itemSeedPotato", ItemRegistry::getMaxItemID(), **VanillaBlocks::mPotatoCrop));

	universalBucket = ItemRegistry::registerItem<UniversalBucket>("zenova:bucketFilled", ItemRegistry::getMaxItemID());
}

void ENItems::initCreativeItems() {
	Item::beginCreativeGroup("itemGroup.name.hammers", hammerWood.get(), 0, nullptr);
	Item::addCreativeItem(hammerWood.get(), 0);
	Item::addCreativeItem(hammerStone.get(), 0);
	Item::addCreativeItem(hammerIron.get(), 0);
	Item::addCreativeItem(hammerDiamond.get(), 0);
	Item::addCreativeItem(hammerGold.get(), 0);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.crooks", crookWood.get(), 0, nullptr);
	Item::addCreativeItem(crookWood.get(), 0);
	Item::addCreativeItem(crookBone.get(), 0);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.resources", resources.get(), 1, nullptr);
	for (int i = 1; i < 6; i++)
		Item::addCreativeItem(resources.get(), i);
	Item::addCreativeItem(cookedSilkworm.get(), 0);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.pebbles", pebbles.get(), 0, nullptr);
	for (int i = 0; i < 4; i++)
		Item::addCreativeItem(pebbles.get(), i);
	Item::endCreativeGroup();
	
	Item::beginCreativeGroup("itemGroup.name.dolls", dolls.get(), 0, nullptr);
	for (int i = 0; i < 2; i++)
		Item::addCreativeItem(dolls.get(), i);
	Item::endCreativeGroup();

	Item::beginCreativeGroup("itemGroup.name.seeds", itemSeedSaplings.get(), 0, nullptr);
	for (int i = 1; i < 6; i++)
		Item::addCreativeItem(itemSeedSaplings.get(), i);
	for (WeakPtr<ItemSeedBase> item : itemSeeds)
		Item::addCreativeItem(item.get(), 0);
	Item::endCreativeGroup();

	for (int i = 0; i < FluidRegistry::mFluids.size(); i++)
		Item::addCreativeItem(universalBucket.get(), i);
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
	pebbles->setIcon("itemPebble", 0);
	dolls->setIcon("itemDoll", 0);
	itemSeedSaplings->setIcon("itemSeed", 0);
	itemSeeds[0]->setIcon("itemSeed", 6);
	itemSeeds[1]->setIcon("itemSeed", 7);
	itemSeeds[2]->setIcon("itemSeed", 8);
	itemSeeds[3]->setIcon("itemSeed", 9);
	
	universalBucket->setIcon("bucket", 0);
}