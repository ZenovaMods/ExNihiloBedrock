#pragma once

#include "minecraft/item/BlockPlanterItem.h"
#include "minecraft/client/TextureAtlasItem.h"

class ItemSeedBase : public BlockPlanterItem {
public:
	static const std::string OAK;
	static const std::string SPRUCE;
	static const std::string BIRCH;
	static const std::string JUNGLE;
	static const std::string ACACIA;
	static const std::string DARK_OAK;

private:
	static std::string names[6];
	TextureAtlasItem textureItem;
	bool hasSubItems;

public:
	ItemSeedBase(const std::string& name, int id, const Block& block, bool subItems = false);
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);
};