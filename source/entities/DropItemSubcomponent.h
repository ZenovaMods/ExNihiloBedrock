#pragma once

#include "minecraft/actor/OnHitSubcomponent.h"
#include "minecraft/actor/Actor.h"
#include "minecraft/world/Spawner.h"
#include "minecraft/actor/ProjectileComponent.h"
#include "minecraft/world/Level.h"
#include "minecraft/item/ItemStack.h"
#include "../items/ENItems.h"
#include "../items/ItemPebble.h"
#include "ProjectileStone.h"

class DropItemSubcomponent : public OnHitSubcomponent {
public:
	DropItemSubcomponent() : OnHitSubcomponent() {}
	virtual ~DropItemSubcomponent() {}
	virtual void readfromJSON(Json::Value&) {}
	virtual void writetoJSON(Json::Value&) const {}
	virtual void doOnHitEffect(Actor& owner, ProjectileComponent& component) {
		Level& level = owner.getLevel();
		if (!level.isClientSide() && component.getHitResult().getHitResultType() == HitResultType::TILE) {
			short auxValue = 0;
			if (owner.getEntityTypeId() == ActorType::Pebble)
				auxValue = dynamic_cast<ProjectileStone&>(owner).getStoneType();
			ItemStack stack = ItemStack(*ENItems::pebbles, 1, auxValue);
			level.getSpawner().spawnItem(owner.getRegion(), stack, &owner, component.getHitResult().getPos(), 0);
		}
	}
	static const char* getSubcomponentName() { return "drop_item"; }
};