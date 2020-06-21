#pragma once

#include "minecraft/item/Item.h"
#include "minecraft/client/TextureAtlasItem.h"

class ItemDoll : public Item {
private:
	static std::vector<std::string> names;
	TextureAtlasItem textureItem;

public:
	ItemDoll(const std::string&, int);
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);

	bool spawnMob(ItemStack&, Actor&, const BlockPos&) const;
};