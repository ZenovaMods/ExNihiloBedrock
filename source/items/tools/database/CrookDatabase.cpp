#include "CrookDatabase.h"

#include <algorithm>

#include "minecraft/ItemStack.h"
#include "minecraft/Item.h"

std::vector<Item*> CrookDatabase::crookDatabase;

void CrookDatabase::registerCrook(Item* crook) {
	crookDatabase.emplace_back(crook);
}

bool CrookDatabase::isCrook(const ItemStackBase& item) {
	return std::find(std::begin(crookDatabase), std::end(crookDatabase), item.getItem()) != std::end(crookDatabase);
}