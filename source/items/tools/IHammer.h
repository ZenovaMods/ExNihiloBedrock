#pragma once

class ItemStackBase;

class IHammer {
public:
	virtual int getMiningLevel(const ItemStackBase&) = 0;
};