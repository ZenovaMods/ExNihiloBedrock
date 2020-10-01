#pragma once

#include <chrono>

#include "Item.h"
#include "../block/Block.h"
#include "../util/CompoundTag.h"

class Tick { uint64_t tickID; };

struct SortItemInstanceIdAux {
	bool operator()(const ItemInstance&, const ItemInstance&) const;
};

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
	Tick mBlockingTick;
private:
	std::unique_ptr<ItemInstance> mChargedItem;

public:
	virtual ~ItemStackBase();
	virtual void reinit(const BlockLegacy&, int) = 0;

protected:
	ItemStackBase();
	ItemStackBase(const BlockLegacy&, int);
	ItemStackBase(const Block&, int, const CompoundTag*);
	ItemStackBase(const Item&, int, int);
	ItemStackBase(const ItemStackBase&);
	ItemStackBase& operator=(const ItemStackBase&);
	virtual void reinit(const Item&, int, int) = 0;

public:
	void add(const int inCount) {
		set(mCount + inCount);
	}
	void remove(const int inCount) {
		set(mCount - inCount);
	}
	void set(const int);
	bool hasUserData() const {
		return mUserData != nullptr;
	}
	const Item* getItem() const;
	const Block* getBlock() const {
		return mBlock;
	}
	short getAuxValue() const;
	byte getStackSize() const {
		return mCount;
	}
	bool isEmptyStack() const {
		return mCount == 0;
	}
	bool isInstance(const Item& i) const {
		return &i == mItem.get();
	}
	bool matchesItem(const ItemStackBase&) const;
};

class ItemStack : public ItemStackBase {
public:
	ItemStack();
	ItemStack(const BlockLegacy&, int);
	ItemStack(const Item&, int);
	ItemStack(const Item& item, int count, int aux) : ItemStackBase(item, count, aux) {}

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
	ItemInstance(const ItemStack& stack) : ItemStackBase(stack) {}

	ItemInstance clone() const { return ItemInstance(*this); }

	virtual void reinit(const BlockLegacy&, int);
protected:
	virtual void reinit(const Item&, int, int);
};