#pragma once

#include <vector>
#include <string>

#include "minecraft/util/SharedPtr.h"
#include "minecraft/util/Color.h"

class Ore;
class ItemOre;
class ItemInfo;
class Recipes;

class OreRegistry {
private:
	static std::vector<Ore*> registry;
	static std::vector<Ore*> externalRegistry;
	static std::vector<WeakPtr<ItemOre>> itemOreRegistry;

public:
	static void registerDefaults();
	static Ore* registerOre(const std::string&, const Color&, ItemInfo*);
	static Ore* registerInternal(const std::string&, const Color&, ItemInfo*);
	static void registerFromRegistry();
	static void doRecipes(Recipes&);
	static void initClientData();
	static void initCreativeItems();
	static void loadJson(const std::string&);
	static void saveJson(const std::string&);
};