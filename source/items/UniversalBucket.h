#pragma once

#include "minecraft/item/BucketItem.h"

class UniversalBucket : public Item {
private:
	std::vector<TextureUVCoordinateSet> mBucketTextures;

public:
	UniversalBucket(const std::string& nameId, int id);
	virtual bool isValidAuxValue(int) const;
	virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
	virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
	virtual Item& setIcon(const std::string&, int);
	virtual std::string getAuxValuesDescription() const;
	static bool _takeLiquid(ItemStack&, Actor&, const BlockPos&);

private:
	virtual bool _useOn(ItemStack&, Actor&, BlockPos, FacingID, float, float, float) const;
	bool _emptyBucket(BlockSource&, const Block&, const BlockPos&, Actor*, const ItemStack&, FacingID) const;
	bool _canEmptyBucketIntoBlock(const Block&, const Block&) const;
};