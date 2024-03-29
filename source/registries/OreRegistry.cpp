#include "OreRegistry.h"

#include "minecraft/item/ItemStack.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/item/Recipes.h"

#include "../util/ItemInfo.h"
#include "manager/RegistryManager.h"
#include "manager/IOreDefaultRegistryProvider.h"
#include "../items/ore/ItemOre.h"

std::vector<Ore*> OreRegistry::registry;
std::vector<Ore*> OreRegistry::externalRegistry;
std::vector<WeakPtr<ItemOre>> OreRegistry::itemOreRegistry;

void OreRegistry::registerDefaults() {
	for (IOreDefaultRegistryProvider* provider : RegistryManager::getDefaultOreRecipeHandlers()) {
		provider->registerOreRecipeDefaults();
	}
}

/**
 * Registers a new custom piece, hunk, dust and potentially ingot to be
 * generated by Ex Nihilo Adscensio.
 *
 * @param name
 *            Unique name for ore
 * @param color
 *            Color for the pieces
 * @param info
 *            Final result for the process. If null, an ingot is generated.
 *            Otherwise, the hunk will be smelted into this.
 * @return Ore, containing the base Ore object.
 */
Ore* OreRegistry::registerOre(const std::string& name, const Color& color, ItemInfo* info) {
	Ore* ore = registerInternal(name, color, info);
	externalRegistry.push_back(ore);
	return ore;
}

/**
 * Registers a new custom piece, hunk, dust and potentially ingot to be
 * generated by Ex Nihilo Adscensio.
 *
 * @param name
 *            Unique name for ore
 * @param color
 *            Color for the pieces
 * @param info
 *            Final result for the process. If null, an ingot is generated.
 *            Otherwise, the hunk will be smelted into this.
 * @return Ore, containing the base Ore object.
 */
Ore* OreRegistry::registerInternal(const std::string& name, const Color& color, ItemInfo* info) {
	Ore* ore = new Ore(name, color, info);
	registry.push_back(ore);
	WeakPtr<ItemOre> oreItem = ItemRegistry::registerItem<ItemOre>(ore->getName(), ItemRegistry::getMaxItemID(), ore);
	itemOreRegistry.push_back(oreItem);
	return ore;
}

void OreRegistry::registerFromRegistry() {
	for (Ore* ore : registry) {
		WeakPtr<ItemOre> oreItem = ItemRegistry::registerItem<ItemOre>(ore->getName(), ItemRegistry::getMaxItemID(), ore);
		itemOreRegistry.push_back(oreItem);
	}
}

void OreRegistry::doRecipes(Recipes& recipes) {
	for (WeakPtr<ItemOre> ore : itemOreRegistry) {
		std::string recipeId = "exnihilo:chunk_from_piece_" + ore->getOre()->getName();
		recipes.addShapedRecipe(recipeId, ItemInstance(*ore, 1, 1), "xx", "xx", { {'x', {*ore, 0, 1}} }, { {"crafting_table"} }, 50, nullptr);

		ItemInstance smeltingResult;

		if (ore->isRegisterIngot())
			smeltingResult = ItemInstance(*ore, 1, 3);
		else
			smeltingResult = *ore->getOre()->getResult()->getItemStack();

		recipes.addFurnaceRecipeAuxData(ItemInstance(*ore, 1, 1), smeltingResult, { {"furnace"}, {"blast_furnace"} });
		recipes.addFurnaceRecipeAuxData(ItemInstance(*ore, 1, 2), smeltingResult, { {"furnace"}, {"blast_furnace"} });
	}
}

void OreRegistry::initClientData() {
	for (WeakPtr<ItemOre> item : itemOreRegistry) {
		item->setIcon("itemOre", 0);
	}
}

void OreRegistry::initCreativeItems() {
	if (itemOreRegistry.size() > 0) {
		Item::beginCreativeGroup("itemGroup.name.orepieces", itemOreRegistry[0].get(), 0, nullptr);
		for (WeakPtr<ItemOre> item : itemOreRegistry) {
			Item::addCreativeItem(item.get(), 0);
		}
		Item::endCreativeGroup();
		Item::beginCreativeGroup("itemGroup.name.orehunks", itemOreRegistry[0].get(), 1, nullptr);
		for (WeakPtr<ItemOre> item : itemOreRegistry) {
			Item::addCreativeItem(item.get(), 1);
		}
		Item::endCreativeGroup();
		Item::beginCreativeGroup("itemGroup.name.oredusts", itemOreRegistry[0].get(), 2, nullptr);
		for (WeakPtr<ItemOre> item : itemOreRegistry) {
			Item::addCreativeItem(item.get(), 2);
		}
		Item::endCreativeGroup();
		bool hasIngotGroup = false;
		for (WeakPtr<ItemOre> item : itemOreRegistry) {
			if (item->isRegisterIngot()) {
				if (!hasIngotGroup) {
					Item::beginCreativeGroup("itemGroup.name.oreingots", item.get(), 3, nullptr);
					hasIngotGroup = true;
				}
				Item::addCreativeItem(item.get(), 3);
			}
		}
		if (hasIngotGroup)
			Item::endCreativeGroup();
	}
}

void OreRegistry::loadJson(const std::string& filePath) {
	registry.clear();
	itemOreRegistry.clear();

	/*if (file.exists()) {
		try {
			FileReader fr = new FileReader(file);
			List<Ore> gsonInput = gson.fromJson(fr, new TypeToken<List<Ore>>() {
			}.getType());

			registry.addAll(gsonInput);
			registerFromRegistry();
			registry.addAll(externalRegistry);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	else {*/
	registerDefaults();
	saveJson(filePath);
	//}
}

void OreRegistry::saveJson(const std::string& path) {
	/*try {
		FileWriter fw = new FileWriter(file);
		gson.toJson(registry, fw);

		fw.close();
	} catch (Exception e) {
		e.printStackTrace();
	}*/
}