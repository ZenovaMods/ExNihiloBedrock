#pragma once

#include <vector>
#include "minecraft/SharedPtr.h"

class HammerBase;
class CrookBase;
class ItemResource;
class ItemCookedSilkworm;
class ItemSeedBase;
class BlockPlanterItem;

class ENItems {
public:
	static WeakPtr<HammerBase> hammerWood;
	static WeakPtr<HammerBase> hammerStone;
	static WeakPtr<HammerBase> hammerIron;
	static WeakPtr<HammerBase> hammerDiamond;
	static WeakPtr<HammerBase> hammerGold;

	static WeakPtr<CrookBase> crookWood;
	static WeakPtr<CrookBase> crookBone;

	static WeakPtr<ItemResource> resources;
	static WeakPtr<ItemCookedSilkworm> cookedSilkworm;

	static WeakPtr<ItemSeedBase> itemSeedSaplings;
	static std::vector<WeakPtr<ItemSeedBase>> itemSeeds;


	static void init();
	static void initCreativeCategories();
	static void initCreativeItems();
	static void initClientData();
};