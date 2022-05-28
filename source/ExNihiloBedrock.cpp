#include "ExNihiloBedrock.h"
#include "generated/initcpp.h"
#include "Zenova/Minecraft.h"

#include <iostream>

#include "minecraft/item/BucketItem.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/item/Recipes.h"
#include "minecraft/item/VanillaItems.h"
#include "minecraft/block/BlockDefinitionGroup.h"
#include "minecraft/block/BlockLegacy.h"
#include "minecraft/blockactor/BlockActorFactory.h"
#include "minecraft/world/WorldSystems.h"
#include "minecraft/client/ActorRenderDispatcher.h"
#include "minecraft/client/BlockActorRenderDispatcher.h"
#include "minecraft/client/BlockGraphics.h"
#include "minecraft/client/BlockTessellator.h"
#include "minecraft/client/Tessellator.h"
#include "minecraft/actor/ActorRegistry.h"
#include "minecraft/actor/ActorType.h"
#include "minecraft/actor/ProjectileFactory.h"

#include "items/ENItems.h"
#include "items/UniversalBucket.h"
#include "blocks/ENBlocks.h"
#include "blocks/BlockRegistry.h"
#include "blocks/BlockTessellatorRegistry.h"
#include "blockactors/BlockActorRegistry.h"
#include "blockactors/InfestingLeavesREnderer.h"
#include "entities/ENEntities.h"
#include "handlers/HandlerCrook.h"
#include "handlers/HandlerHammer.h"
#include "registries/HammerRegistry.h"
#include "registries/CrookRegistry.h"
#include "registries/OreRegistry.h"
#include "registries/manager/ExNihiloDefaultRecipes.h"

void (*_registerItems)(bool);
void registerItems(bool b1) {
	_registerItems(b1);

	ENItems::init();
	ENBlocks::initBlockItems();
}

void (*_initCreativeItemsCallback)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
void initCreativeItemsCallback(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool b1) {
	_initCreativeItemsCallback(actorInfoRegistry, blockDefinitionGroup, b1);

	ENItems::initCreativeItems();
	ENBlocks::initCreativeBlocks();
	OreRegistry::initCreativeItems();
}

void (*_initClientData)();
void initClientData() {
	_initClientData();

	ENItems::initClientData();
	OreRegistry::initClientData();
}

void (*_initWorldSystems)(WorldSystems*, ResourcePackManager*);
void initWorldSystems(WorldSystems* self, ResourcePackManager* rpm) {
	bool mInitialized = *WorldSystems::mInitialized;
	_initWorldSystems(self, rpm);
	if (*WorldSystems::mInitialized && !mInitialized) {
		HammerRegistry::loadJson("HammerRegistry.json");
		CrookRegistry::loadJson("CrookRegistry.json");
		OreRegistry::loadJson("OreRegistry.json");
	}
}

void (*_registerBlocks)(BlockDefinitionGroup*);
void registerBlocks(BlockDefinitionGroup* self) {
	for (auto block : Zenova::BlockRegistry::BlockRegistryList)
		block->initBlock(self);

	_registerBlocks(self);
}

void (*_registerLooseBlockGraphics)(std::vector<Json::Value>&, const BlockPalette&);
void registerLooseBlockGraphics(std::vector<Json::Value>& json, const BlockPalette& palette) {
	for (auto block : Zenova::BlockRegistry::BlockRegistryList)
		block->initBlockGraphics(json);

	_registerLooseBlockGraphics(json, palette);
}

void (*_BlockLegacy_playerDestroy)(BlockLegacy*, Player&, const BlockPos&, const Block&);
void BlockLegacy_playerDestroy(BlockLegacy* self, Player& player, const BlockPos& pos, const Block& block) {
	if (!HandlerHammer::hammer(block, pos, player) && !HandlerCrook::crook(block, pos, player))
		_BlockLegacy_playerDestroy(self, player, pos, block);
}

void (*_initBlockEntityRenderers)(BlockActorRenderDispatcher*, GeometryGroup&, mce::TextureGroup&, BlockTessellator&, const ActorResourceDefinitionGroup&);
void initBlockEntityRenderers(BlockActorRenderDispatcher* self, GeometryGroup& geometry, mce::TextureGroup& textures, BlockTessellator& blockTessellator, const ActorResourceDefinitionGroup& definitions) {
	_initBlockEntityRenderers(self, geometry, textures, blockTessellator, definitions);

	self->mRendererMap[BlockActorRendererId::TR_INFESTINGLEAVES_RENDERER] = std::make_unique<InfestingLeavesRenderer>(textures, blockTessellator);
}

bool (*_tessellateInWorld)(BlockTessellator*, Tessellator&, const Block&, const BlockPos&, void*);
bool tessellateInWorld(BlockTessellator* self, Tessellator& tessellator, const Block& block, const BlockPos& pos, void* idk) {
	if (!Zenova::BlockTessellatorRegistry::tessellateInWorld(self, tessellator, block, pos))
		return _tessellateInWorld(self, tessellator, block, pos, idk);
	return true;
}

bool (*_canRenderBlockInGui)(BlockShape);
bool canRenderBlockInGui(BlockShape shape) {
	if (!Zenova::BlockTessellatorRegistry::canRender(shape))
		return _canRenderBlockInGui(shape);
	return true;
}

std::shared_ptr<BlockActor>(*_createBlockEntity)(BlockActorType, const BlockPos&, const BlockLegacy&);
std::shared_ptr<BlockActor> createBlockEntity(BlockActorType type, const BlockPos& pos, const BlockLegacy& block) {
	std::shared_ptr<BlockActor> blockActor = _createBlockEntity(type, pos, block);
	if (!blockActor)
		return Zenova::BlockActorRegistry::createBlockEntity(type, pos);
	return blockActor;
}

void (*_initBlockEntities)();
void initBlockEntities() {
	_initBlockEntities();

	Zenova::BlockActorRegistry::initBlockEntities();
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

bool (*_bucketTakeLiquid)(const BucketItem*, ItemStack&, Actor&, const BlockPos&);
bool bucketTakeLiquid(const BucketItem* self, ItemStack& itemStack, Actor& entity, const BlockPos& pos) {
	if (!UniversalBucket::_takeLiquid(itemStack, entity, pos))
		return _bucketTakeLiquid(self, itemStack, entity, pos);
	return true;
}

bool (*_bucketDispense)(const BucketItem*, BlockSource&, Container&, int, const Vec3&, FacingID);
bool bucketDispense(const BucketItem* self, BlockSource& region, Container& container, int slot, const Vec3& pos, FacingID face) {
	if (!UniversalBucket::dispenseEmpty(region, container, slot, pos, face))
		return _bucketDispense(self, region, container, slot, pos, face);
	return true;
}

void (*_initRecipes)(Recipes*, ResourcePackManager&);
void initRecipes(Recipes* self, ResourcePackManager& resourcePackManager) {
	_initRecipes(self, resourcePackManager);

	OreRegistry::doRecipes(*self);
}

ExNihiloDefaultRecipes* ExNihiloBedrock::defaultRecipes;


void ExNihiloBedrock::Start() {
	Zenova_Info("Intializing Ex Nihilo and checking version");
	Zenova::Platform::DebugPause();

	if (Zenova::Minecraft::version() == Zenova::Minecraft::v1_14_60_5) {
		defaultRecipes = new ExNihiloDefaultRecipes();

		ENEntities::initEntityMap();
		ENBlocks::init();

		Zenova_Hook(VanillaItems::registerItems, &registerItems, &_registerItems);
		Zenova_Hook(VanillaItems::initCreativeItemsCallback, &initCreativeItemsCallback, &_initCreativeItemsCallback);
		Zenova_Hook(VanillaItems::initClientData, &initClientData, &_initClientData);
		Zenova_VHook(BlockLegacy, playerDestroy, &BlockLegacy_playerDestroy, &_BlockLegacy_playerDestroy);
		Zenova_Hook(WorldSystems::init, &initWorldSystems, &_initWorldSystems);
		Zenova_Hook(BlockGraphics::registerLooseBlockGraphics, &registerLooseBlockGraphics, &_registerLooseBlockGraphics);
		Zenova_Hook(BlockDefinitionGroup::registerBlocks, &registerBlocks, &_registerBlocks);
		Zenova_Hook(BlockActorRenderDispatcher::initializeBlockEntityRenderers, &initBlockEntityRenderers, &_initBlockEntityRenderers);
		Zenova_Hook(BlockTessellator::tessellateInWorld, &tessellateInWorld, &_tessellateInWorld);
		Zenova_Hook(BlockTessellator::canRender, &canRenderBlockInGui, &_canRenderBlockInGui);
		Zenova_Hook(BlockActorFactory::createBlockEntity, &createBlockEntity, &_createBlockEntity);
		Zenova_Hook(BlockActor::initBlockEntities, &initBlockEntities, &_initBlockEntities);
		Zenova_Hook(ProjectileFactory::initFactory, &initProjectileFactory, &_initProjectileFactory);
		Zenova_Hook(ActorRenderDispatcher::initializeEntityRenderers, &initEntityRenderers, &_initEntityRenderers);
		Zenova_Hook(VanillaActors::registerVanillaActorData, &registerVanillaActorData, &_registerVanillaActorData);
		Zenova_Hook(BucketItem::_takeLiquid, &bucketTakeLiquid, &_bucketTakeLiquid);
		Zenova_VHook(BucketItem, dispense, &bucketDispense, &_bucketDispense);
		Zenova_Hook(Recipes::init, &initRecipes, &_initRecipes);
	}
}

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new ExNihiloBedrock;
}
