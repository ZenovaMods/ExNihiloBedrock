#pragma once

#include "minecraft/OnHitSubcomponent.h"
#include "minecraft/Actor.h"
#include "minecraft/Spawner.h"
#include "minecraft/ProjectileComponent.h"
#include "minecraft/Level.h"
#include "minecraft/ItemStack.h"
#include "../items/ENItems.h"
#include "../items/ItemPebble.h"

class DropItemSubcomponent : public OnHitSubcomponent {
public:
	DropItemSubcomponent() : OnHitSubcomponent() {}
	virtual ~DropItemSubcomponent() {}
	virtual void readfromJSON(Json::Value&) {}
	virtual void writetoJSON(Json::Value&) const {}
	virtual void doOnHitEffect(Actor& owner, ProjectileComponent& component) {
		Level& level = owner.getLevel();
		if (!level.isClientSide() && component.getHitResult().getHitResultType() == HitResultType::TILE) {
			ItemStack stack = ItemStack(*ENItems::pebbles, 1, owner.getEntityData().getShort(0x24));
			level.getSpawner().spawnItem(owner.getRegion(), stack, &owner, component.getHitResult().getPos(), 0);
		}
	}
	static const char* getSubcomponentName() { return "drop_item"; }
};