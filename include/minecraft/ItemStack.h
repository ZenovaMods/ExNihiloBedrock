#pragma once

#include <chrono>

class Block;
class BlockLegacy;
class Item;
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

protected:
    virtual ~ItemStackBase();
public:
    ItemStackBase(const Item&, int, int);
    void add(const int inCount) {
        set(mCount + inCount);
    }
    void remove(const int inCount) {
        set(mCount - inCount);
    }
    void set(const int);
    short getAuxValue() const;
};

class ItemStack : public ItemStackBase {
protected:
    virtual ~ItemStack();
};

class ItemInstance : public ItemStackBase {
protected:
    virtual ~ItemInstance();
};