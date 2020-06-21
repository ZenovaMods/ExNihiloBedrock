#pragma once

#include "minecraft/item/Item.h"
#include "minecraft/client/TextureAtlasItem.h"

class ItemPebble : public Item {
private:
	static std::vector<std::string> names;
	TextureAtlasItem textureItem;

public:
	ItemPebble(const std::string&, int);
	virtual bool isThrowable() const;
	virtual bool isValidAuxValue(int) const;
	virtual ItemStack& use(ItemStack&, Player&) const;
	virtual bool dispense(BlockSource&, Container&, int, const Vec3&, unsigned char) const;
	virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);

public:
	static ItemInstance* getPebbleStack(const std::string&);
};