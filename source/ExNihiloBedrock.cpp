#include "ExNihiloBedrock.h"
#include "main.h"

#include <iostream>

#include "minecraft/item/ItemStack.h"
#include "minecraft/item/VanillaItems.h"
#include "minecraft/block/BlockDefinitionGroup.h"
#include "minecraft/block/BlockLegacy.h"
#include "minecraft/world/WorldSystems.h"
#include "minecraft/client/BlockGraphics.h"
#include "minecraft/client/ActorRenderDispatcher.h"
#include "minecraft/actor/ActorType.h"
#include "minecraft/actor/ProjectileFactory.h"
#include "minecraft/actor/ActorRegistry.h"

#include "items/ENItems.h"
#include "blocks/ENBlocks.h"
#include "entities/ENEntities.h"
#include "handlers/HandlerCrook.h"
#include "handlers/HandlerHammer.h"
#include "registries/HammerRegistry.h"
#include "registries/CrookRegistry.h"
#include "registries/manager/ExNihiloDefaultRecipes.h"

void (*_registerItems)(bool);
void registerItems(bool b1) {
	_registerItems(b1);

	ENItems::init();
	ENBlocks::initBlockItems();
}

void (*_initCreativeCategories)();
void initCreativeCategories() {
	_initCreativeCategories();

	ENItems::initCreativeCategories();
}

void (*_initCreativeItemsCallback)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
void initCreativeItemsCallback(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool b1) {
	_initCreativeItemsCallback(actorInfoRegistry, blockDefinitionGroup, b1);

	ENItems::initCreativeItems();
	ENBlocks::initCreativeBlocks();
}

void (*_initClientData)();
void initClientData() {
	_initClientData();

	ENItems::initClientData();
}

void (*_initWorldSystems)(WorldSystems*, ResourcePackManager*);
void initWorldSystems(WorldSystems* self, ResourcePackManager* rpm) {
	static bool mInitialized = false;
	_initWorldSystems(self, rpm);
	if (*WorldSystems::mInitialized && !mInitialized) {
		HammerRegistry::loadJson("HammerRegistry.json");
		CrookRegistry::loadJson("CrookRegistry.json");
		mInitialized = true;
	}
}

void (*_registerBlocks)(BlockDefinitionGroup*);
void registerBlocks(BlockDefinitionGroup* self) {
	ENBlocks::init(self);

	_registerBlocks(self);
}

void (*_registerLooseBlockGraphics)(std::vector<Json::Value>&, const BlockPalette&);
void registerLooseBlockGraphics(std::vector<Json::Value>& json, const BlockPalette& palette) {
	ENBlocks::initGraphics(json);

	_registerLooseBlockGraphics(json, palette);
}

void (*_BlockLegacy_playerDestroy)(BlockLegacy*, Player&, const BlockPos&, const Block&);
void BlockLegacy_playerDestroy(BlockLegacy* self, Player& player, const BlockPos& pos, const Block& block) {
	if (!HandlerHammer::hammer(block, pos, player) && !HandlerCrook::crook(block, pos, player))
		_BlockLegacy_playerDestroy(self, player, pos, block);
}

void (*_initProjectileFactory)();
void initProjectileFactory() {
	_initProjectileFactory();

	ENEntities::initProjectileMap();
}

void (*_initEntityRenderers)(ActorRenderDispatcher*, GeometryGroup&, mce::TextureGroup&, BlockTessellator&, const ActorResourceDefinitionGroup&, const SemVersion&);
void initEntityRenderers(ActorRenderDispatcher* self, GeometryGroup& geometry, mce::TextureGroup& textures, BlockTessellator& blockTessellator, const ActorResourceDefinitionGroup& definitions, const SemVersion& version) {
	_initEntityRenderers(self, geometry, textures, blockTessellator, definitions, version);

	ENEntities::initRenderers(self, textures);
}

void (*_registerVanillaActorData)();
void registerVanillaActorData() {
	_registerVanillaActorData();

	ENEntities::initEntityData();
}

ExNihiloDefaultRecipes* ExNihiloBedrock::defaultRecipes;
std::string ExNihiloBedrock::versionId;

void ExNihiloBedrock::Start() {
	Zenova::Platform::DebugPause();
	Zenova_Info("ExNihiloBedrock Start");
	versionId = GetManager().GetLaunchedVersion();

	if (versionId == "1.14.60.5") {
		defaultRecipes = new ExNihiloDefaultRecipes();

		ENEntities::initEntityMap();

		Zenova::Hook::Create(&VanillaItems::registerItems, &registerItems, &_registerItems);
		Zenova::Hook::Create(&VanillaItems::initCreativeCategories, &initCreativeCategories, &_initCreativeCategories);
		Zenova::Hook::Create(&VanillaItems::initCreativeItemsCallback, &initCreativeItemsCallback, &_initCreativeItemsCallback);
		Zenova::Hook::Create(&VanillaItems::initClientData, &initClientData, &_initClientData);
		Zenova::Hook::Create(BlockLegacy_vtable, &BlockLegacy::playerDestroy, &BlockLegacy_playerDestroy, &_BlockLegacy_playerDestroy);
		Zenova::Hook::Create(&WorldSystems::init, &initWorldSystems, &_initWorldSystems);
		Zenova::Hook::Create(&BlockGraphics::registerLooseBlockGraphics, &registerLooseBlockGraphics, &_registerLooseBlockGraphics);
		Zenova::Hook::Create(&BlockDefinitionGroup::registerBlocks, &registerBlocks, &_registerBlocks);
		Zenova::Hook::Create(&ProjectileFactory::initFactory, &initProjectileFactory, &_initProjectileFactory);
		Zenova::Hook::Create(&ActorRenderDispatcher::initializeEntityRenderers, &initEntityRenderers, &_initEntityRenderers);
		Zenova::Hook::Create(&VanillaActors::registerVanillaActorData, &registerVanillaActorData, &_registerVanillaActorData);
	}
}

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new ExNihiloBedrock;
}
