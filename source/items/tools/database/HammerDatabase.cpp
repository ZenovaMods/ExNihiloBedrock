#include "HammerDatabase.h"

#include <algorithm>

#include "minecraft/ItemStack.h"
#include "minecraft/Item.h"

std::vector<Item*> HammerDatabase::hammerDatabase;

void HammerDatabase::registerHammer(Item* hammer) {
	hammerDatabase.emplace_back(hammer);
}

bool HammerDatabase::isHammer(const ItemStackBase& item) {
	return std::find(std::begin(hammerDatabase), std::end(hammerDatabase), item.getItem()) != std::end(hammerDatabase);
}