#include "ItemCookedSilkworm.h"

#include "minecraft/FoodItemComponent.h"

ItemCookedSilkworm::ItemCookedSilkworm(const std::string& name, int id) : Item(name, id) {
	setUseAnimation(UseAnimation::EAT);
	setMaxUseDuration(32);
	mFoodComponent = std::make_unique<FoodItemComponent>(*this, 2, 0.6F);
}