#pragma once

#include "minecraft/item/Item.h"
#include "minecraft/client/TextureAtlasItem.h"

#include "Ore.h"

class ItemOre : public Item {
private:
	bool registerIngot;
	Ore* ore;
	TextureAtlasItem textureItem;

	static const std::vector<std::string> ORE_TYPES;

public:
	ItemOre(const std::string&, int, Ore*);
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);
	virtual Color getColor(const std::unique_ptr<CompoundTag>&, const ItemDescriptor&) const;
	virtual bool isTintable() const;

	bool isRegisterIngot() const { return registerIngot; }
	Ore* getOre() const { return ore; }
};