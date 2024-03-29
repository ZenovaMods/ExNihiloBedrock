#include "CrookBase.h"

#include "../ENItems.h"

#include "minecraft/item/VanillaItemTiers.h"

#include "database/CrookDatabase.h"
#include "../../registries/CrookRegistry.h"

CrookBase::CrookBase(const std::string& name, int id, int maxUses)
	: DiggerItem(name, id, 0, VanillaItemTiers::WOOD, {}) {

	setMaxDamage(maxUses);
	setCategory(CreativeItemCategory::TOOLS);
	CrookDatabase::registerCrook(this);
}

float CrookBase::getDestroySpeed(const ItemInstance& item, const Block& block) const {
	return CrookRegistry::registered(&block) ? mSpeed : 1.0f;
}
