#pragma once

#include <functional>
#include <vector>
#include <string>

class BlockSource;
class CompoundTag;
class ContainerContentChangeListener;
class ItemDescriptor;
class ItemInstance;
class ItemStack;
class Player;
class Vec3;

class Container {
public:
    virtual ~Container();
    virtual void init();
    virtual void addContentChangeListener(ContainerContentChangeListener*);
    virtual void removeContentChangeListener(ContainerContentChangeListener*);
    virtual const ItemStack& getItem(int) const;
    virtual bool hasRoomForItem(const ItemStack&);
    virtual void addItem(ItemStack&);
    virtual bool addItemToFirstEmptySlot(ItemStack&);
    virtual void setItem(int, const ItemStack&);
    virtual void removeItem(int, int);
    virtual void removeAllItems();
    virtual void dropContents(BlockSource&, const Vec3&, bool);
    virtual int getContainerSize() const;
    virtual int getMaxStackSize() const;
    virtual void startOpen(Player&);
    virtual void stopOpen(Player&);
    virtual std::vector<ItemStack> getSlotCopies() const;
    virtual const std::vector<ItemStack const*> getSlots() const;
    virtual int getItemCount(const ItemDescriptor&);
    virtual int getItemCount(const ItemStack&);
    virtual int findFirstSlotForItem(const ItemStack&) const;
    virtual bool canPushInItem(BlockSource&, int, int, const ItemInstance&) const;
    virtual bool canPullOutItem(BlockSource&, int, int, const ItemInstance&) const;
    virtual void setContainerChanged(int);
    virtual void setContainerMoved();
    virtual void setCustomName(const std::string&);
    virtual bool hasCustomName() const;
    virtual void readAdditionalSaveData(const CompoundTag&);
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void createTransactionContext(std::function<void(Container&, int, const ItemStack&, const ItemStack&)>, std::function<void()>);
    virtual void triggerTransactionChange(int, const ItemStack&, const ItemStack&);
};