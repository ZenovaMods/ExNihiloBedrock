#include "ENEntities.h"

#include "minecraft/actor/ActorType.h"
#include "minecraft/actor/ProjectileFactory.h"
#include "minecraft/actor/ActorRegistry.h"
#include "minecraft/client/ActorRenderDispatcher.h"

#include "DropItemSubcomponent.h"
#include "ProjectileStone.h"
#include "PebbleRenderer.h"
#include "../items/ENItems.h"
#include "../items/ItemPebble.h"

void ENEntities::initEntityMap() {
	ENTITY_TYPE_MAP->insert({ ActorType::Pebble, {"exnihilo", "pebble", "thrown_stone"} });
}

void ENEntities::initEntityData() {
	_registerActorData<ProjectileStone, ActorType::Pebble>("exnihilo:pebble", true, false);
}

void ENEntities::initProjectileMap() {
	ProjectileFactory::mSubcomponentMap->insert({ DropItemSubcomponent::getSubcomponentName(), std::make_unique<DropItemSubcomponent>});
}

void ENEntities::initRenderers(ActorRenderDispatcher* dispatcher, mce::TextureGroup& textures) {
	dispatcher->mRendererMap[EntityCanonicalName(ActorType::Pebble)] = std::make_unique<PebbleRenderer>(textures, ENItems::pebbles.get());
}