#include "ItemCookedSilkworm.h"

#include "minecraft/item/FoodItemComponent.h"

ItemCookedSilkworm::ItemCookedSilkworm(const std::string& name, int id) : Item(name, id) {
	setUseAnimation(UseAnimation::EAT);
	setMaxUseDuration(32);
	setCategory(CreativeItemCategory::ITEMS);
	mFoodComponent = std::make_unique<FoodItemComponent>(*this, 2, 0.6f);
}