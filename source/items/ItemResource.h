#pragma once

#include "minecraft/Item.h"
#include "minecraft/TextureAtlasItem.h"

class ItemResource : public Item {
public:
	static const std::string PORCELAIN_CLAY;
	static const std::string SILKWORM;
	static const std::string ANCIENT_SPORES;
	static const std::string GRASS_SEEDS;
	static const std::string DOLL_BASE;

private:
	static std::string names[6];
	TextureAtlasItem textureItem;

public:
	ItemResource(const std::string&, int);
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);

private:
	virtual bool _useOn(ItemStack&, Actor&, BlockPos, unsigned char, float, float, float) const;

	static ItemStackBase* getResourceStack(const std::string&);
	static ItemStackBase* getResourceStack(const std::string&, int);
};