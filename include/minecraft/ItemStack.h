#pragma once

#include <chrono>

#include "Item.h"
#include "Block.h"

class CompoundTag {};

class ItemStackBase {
protected:
	WeakPtr<Item> mItem;
	std::unique_ptr<CompoundTag> mUserData;
	const Block* mBlock;
	short mAuxValue;
	byte mCount;
	bool mValid;
	std::chrono::steady_clock::time_point mPickupTime;
	static const std::chrono::milliseconds sPickupPopDuration;
	bool mShowPickUp;
	std::vector<BlockLegacy const*> mCanPlaceOn;
	size_t mCanPlaceOnHash;
	std::vector<BlockLegacy const*> mCanDestroy;
	size_t mCanDestroyHash;

public:
	virtual ~ItemStackBase();
	virtual void reinit(const BlockLegacy&, int) = 0;

protected:
	ItemStackBase();
	ItemStackBase(const BlockLegacy&, int);
	ItemStackBase(const Block&, int, const CompoundTag*);
	ItemStackBase(const Item&, int, int);
	ItemStackBase(const ItemStackBase&);
	virtual void reinit(const Item&, int, int) = 0;

public:
	void add(const int inCount) {
		set(mCount + inCount);
	}
	void remove(const int inCount) {
		set(mCount - inCount);
	}
	void set(const int);
	const Item* getItem() const;
	const Block* getBlock() const {
		return mBlock;
	}
	short getAuxValue() const;
};

class ItemStack : public ItemStackBase {
public:
	virtual ~ItemStack();
	virtual void reinit(const BlockLegacy&, int);
protected:
	virtual void reinit(const Item&, int, int);
};

class ItemInstance : public ItemStackBase {
public:
	ItemInstance();
	ItemInstance(const BlockLegacy&, int);
	ItemInstance(const Block&, int, const CompoundTag*);
	ItemInstance(const Item&, int, int);
	ItemInstance(const ItemInstance&);

	ItemInstance clone() const { return ItemInstance(*this); }

	virtual ~ItemInstance();
	virtual void reinit(const BlockLegacy&, int);
protected:
	virtual void reinit(const Item&, int, int);
};