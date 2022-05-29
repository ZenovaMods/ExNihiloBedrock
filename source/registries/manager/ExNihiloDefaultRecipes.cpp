#include "ExNihiloDefaultRecipes.h"

#include "RegistryManager.h"
#include "../HammerRegistry.h"
#include "../CrookRegistry.h"
#include "../OreRegistry.h"
#include "../../blocks/ENBlocks.h"
#include "../../util/BlockInfo.h"
#include "../../util/ItemInfo.h"
#include "../../items/ItemResource.h"

#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/item/VanillaItems.h"

ExNihiloDefaultRecipes::ExNihiloDefaultRecipes() {
	RegistryManager::registerSieveDefaultRecipeHandler(this);
	RegistryManager::registerHammerDefaultRecipeHandler(this);
	RegistryManager::registerCompostDefaultRecipeHandler(this);
	RegistryManager::registerCrookDefaultRecipeHandler(this);
	RegistryManager::registerCrucibleDefaultRecipeHandler(this);
	RegistryManager::registerFluidBlockDefaultRecipeHandler(this);
	RegistryManager::registerFluidTransformDefaultRecipeHandler(this);
	RegistryManager::registerFluidOnTopDefaultRecipeHandler(this);
	RegistryManager::registerHeatDefaultRecipeHandler(this);
	RegistryManager::registerOreDefaultRecipeHandler(this);
}

void ExNihiloDefaultRecipes::registerSieveRecipeDefaults() {
	// todo when adding sieves
}

void ExNihiloDefaultRecipes::registerHammerRecipeDefaults() {
	HammerRegistry::registerRecipe(new BlockInfo(VanillaBlocks::mCobblestone), new ItemInstance(*VanillaBlockTypes::mGravel, 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo(VanillaBlocks::mGravel), new ItemInstance(*VanillaBlockTypes::mSand, 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo(VanillaBlocks::mNetherrack), new ItemInstance(*ENBlocks::netherrackCrushed->get(), 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo(VanillaBlocks::mSand), new ItemInstance(*ENBlocks::dust->get(), 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo(VanillaBlocks::mEndStone), new ItemInstance(*ENBlocks::endstoneCrushed->get(), 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo("minecraft:stone:1"), new ItemInstance(*ENBlocks::graniteCrushed->get(), 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo("minecraft:stone:3"), new ItemInstance(*ENBlocks::dioriteCrushed->get(), 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo("minecraft:stone:5"), new ItemInstance(*ENBlocks::andesiteCrushed->get(), 1), 0, 1.0f, 0.0f);
	HammerRegistry::registerRecipe(new BlockInfo(ENBlocks::graniteCrushed->get(), -1), new ItemInstance(BlockInfo("minecraft:sand:1").getBlockState(), 1, nullptr), 0, 1.0f, 0.0f);
	
	for (int meta = 0; meta < 16; meta++)
		HammerRegistry::registerRecipe(new BlockInfo("minecraft:concrete:" + std::to_string(meta)), new ItemInstance(BlockInfo("minecraft:concrete_powder:" + std::to_string(meta)).getBlockState(), 1, nullptr), 0, 1.0f, 0.0f);

	for (int meta = 0; meta < 16; meta++) {
		BlockInfo* wool = new BlockInfo("minecraft:wool:" + std::to_string(meta));
		HammerRegistry::registerRecipe(wool, new ItemInstance(*ItemInfo("minecraft:string").getItem(), 3, 0), 0, 1.0f, 0.0f);
		HammerRegistry::registerRecipe(wool, new ItemInstance(*ItemInfo("minecraft:string").getItem(), 1, 0), 0, 0.5f, 0.25f);
		HammerRegistry::registerRecipe(wool, new ItemInstance(*ItemInfo("minecraft:dye").getItem(), 1, 15 - meta), 0, 1.0f, 0.0f);

	}
}

void ExNihiloDefaultRecipes::registerCompostRecipeDefaults() {
	// todo when adding compost
}

void ExNihiloDefaultRecipes::registerCrookRecipeDefaults() {
	CrookRegistry::registerRecipe(new BlockInfo(VanillaBlockTypes::mLeaves.get(), -1), ItemResource::getResourceStack(ItemResource::SILKWORM), 0.1f, 0.0f);
	CrookRegistry::registerRecipe(new BlockInfo(VanillaBlockTypes::mLeaves2.get(), -1), ItemResource::getResourceStack(ItemResource::SILKWORM), 0.1f, 0.0f);
}

void ExNihiloDefaultRecipes::registerCrucibleRecipeDefaults() {
	// todo when adding crucibles
}

void ExNihiloDefaultRecipes::registerFluidBlockRecipeDefaults() {
	// todo when adding fluid blocks
}

void ExNihiloDefaultRecipes::registerFluidTransformRecipeDefaults() {
	// todo when adding fluid transform
}

void ExNihiloDefaultRecipes::registerFluidOnTopRecipeDefaults() {
	// todo when adding fluid on top
}

void ExNihiloDefaultRecipes::registerHeatRecipeDefaults() {
	// todo when adding heat
}

void ExNihiloDefaultRecipes::registerOreRecipeDefaults() {
	OreRegistry::registerOre("gold", Color::fromRGB(0xFFFF00), new ItemInfo(VanillaItems::mGoldIngot.get(), 0));
	OreRegistry::registerOre("iron", Color::fromRGB(0xBF8040), new ItemInfo(VanillaItems::mIronIngot.get(), 0));
}