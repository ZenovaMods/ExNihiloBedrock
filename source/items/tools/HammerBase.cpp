#include "HammerBase.h"

#include "../ENItems.h"

#include "database/HammerDatabase.h"
#include "../../registries/HammerRegistry.h"

HammerBase::HammerBase(const std::string& name, int id, int maxUses, Item::Tier material)
	: DiggerItem(name, id, 0, material, {}) {

	setMaxDamage(maxUses);
	setCategory(CreativeItemCategory::TOOLS);
	miningLevel = material.getLevel();
	HammerDatabase::registerHammer(this);
}

int HammerBase::getMiningLevel(const ItemStackBase& item) {
	return miningLevel;
}

float HammerBase::getDestroySpeed(const ItemInstance& item, const Block& block) const {
	return HammerRegistry::registered(&block) ? mSpeed : 1.0f;
}

bool HammerBase::canDestroySpecial(Block const& block) const {
	return HammerRegistry::registered(&block);
}
