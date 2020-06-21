#include "ExNihiloDefaultRecipes.h"

#include "RegistryManager.h"
#include "../HammerRegistry.h"
#include "../CrookRegistry.h"
#include "../../blocks/ENBlocks.h"
#include "../../util/BlockInfo.h"
#include "../../items/ItemResource.h"

#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"
#include "minecraft/item/ItemStack.h"

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
	HammerRegistry::registerRecipe(new BlockInfo(*VanillaBlocks::mCobblestone), new ItemInstance(*VanillaBlockTypes::mGravel->get(), 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(new BlockInfo(*VanillaBlocks::mGravel), new ItemInstance(*VanillaBlockTypes::mSand->get(), 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(new BlockInfo(*VanillaBlocks::mNetherrack), new ItemInstance(*ENBlocks::netherrackCrushed.get(), 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(new BlockInfo(*VanillaBlocks::mSand), new ItemInstance(*ENBlocks::dust.get(), 1), 0, 1.0F, 0.0F);
	HammerRegistry::registerRecipe(new BlockInfo(*VanillaBlocks::mEndStone), new ItemInstance(*ENBlocks::endstoneCrushed.get(), 1), 0, 1.0F, 0.0F);
}

void ExNihiloDefaultRecipes::registerCompostRecipeDefaults() {
	// todo when adding compost
}

void ExNihiloDefaultRecipes::registerCrookRecipeDefaults () {
	CrookRegistry::registerRecipe(new BlockInfo(VanillaBlockTypes::mLeaves->get(), -1), ItemResource::getResourceStack(ItemResource::SILKWORM), 0.1F, 0.0F);
	CrookRegistry::registerRecipe(new BlockInfo(VanillaBlockTypes::mLeaves2->get(), -1), ItemResource::getResourceStack(ItemResource::SILKWORM), 0.1F, 0.0F);
}

void ExNihiloDefaultRecipes::registerCrucibleRecipeDefaults () {
	// todo when adding crucibles
}

void ExNihiloDefaultRecipes::registerFluidBlockRecipeDefaults () {
	// todo when adding fluid blocks
}

void ExNihiloDefaultRecipes::registerFluidTransformRecipeDefaults () {
	// todo when adding fluid transform
}

void ExNihiloDefaultRecipes::registerFluidOnTopRecipeDefaults () {
	// todo when adding fluid on top
}

void ExNihiloDefaultRecipes::registerHeatRecipeDefaults () {
	// todo when adding heat
}

void ExNihiloDefaultRecipes::registerOreRecipeDefaults () {
	// todo when adding ore
}