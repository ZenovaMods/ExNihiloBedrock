#pragma once

#include "Item.h"

class Effect {};

class FoodItemComponent {
	enum class OnUseAction : int {
		NONE = -1,
		CHORUS_TELEPORT,
		SUSPICIOUS_STEW_EFFECT
	};

	const Item& mOwner;
	int mNutrition = 0;
	float mSaturationModifier = 1.0f;
	std::string mUsingConvertsTo;
	OnUseAction mOnUseAction = OnUseAction::NONE;
	Vec3 mOnUseRange{ 8.0f, 8.0f, 8.0f };
	CooldownType mCoolDownType = CooldownType::TypeNone;
	int mCooldownTime = 0;
	bool mCanAlwaysEat = false;
	std::vector<Effect> mEffects;
	std::vector<unsigned int> mRemoveEffects;

public:
	FoodItemComponent(Item& owner, int nutrition, float saturation) :
		mOwner(owner), mNutrition(nutrition), mSaturationModifier(saturation) {}
};