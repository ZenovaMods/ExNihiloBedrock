#pragma once

#include "IHammer.h"

#include "minecraft/DiggerItem.h"

class HammerBase : public DiggerItem, public IHammer {
public:
	int miningLevel;
	
	HammerBase(const std::string&, int, int, Item::Tier);

	virtual int getMiningLevel(const ItemStackBase&);
	virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
	virtual bool canDestroySpecial(const Block&) const;
};