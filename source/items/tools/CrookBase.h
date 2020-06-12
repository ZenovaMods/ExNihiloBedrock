#pragma once

#include "minecraft/DiggerItem.h"

class CrookBase : public DiggerItem {
public:
	CrookBase(const std::string&, int, int);

	virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
};