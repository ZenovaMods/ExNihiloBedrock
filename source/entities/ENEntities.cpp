#include "ENEntities.h"

#include "minecraft/ActorType.h"
#include "minecraft/ProjectileFactory.h"
#include "minecraft/ActorRenderDispatcher.h"
#include "minecraft/ItemSpriteRenderer.h"

#include "DropItemSubcomponent.h"
#include "../items/ENItems.h"
#include "../items/ItemPebble.h"

void ENEntities::initEntityMap() {
	ENTITY_TYPE_MAP->insert({ ActorType::Pebble, {"exnihilo", "pebble", "thrown_stone"} });
}

void ENEntities::initProjectileMap() {
	ProjectileFactory::mSubcomponentMap->insert({ DropItemSubcomponent::getSubcomponentName(), std::make_unique<DropItemSubcomponent>});
}

void ENEntities::initRenderers(ActorRenderDispatcher* dispatcher, mce::TextureGroup& textures) {
	dispatcher->mRendererMap[EntityCanonicalName(ActorType::Pebble)] = std::make_unique<ItemSpriteRenderer>(textures, ENItems::pebbles.get(), false);
}