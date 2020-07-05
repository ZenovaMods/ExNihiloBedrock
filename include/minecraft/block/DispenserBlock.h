#pragma once

#include "ActorBlock.h"

class ItemStack;

class DispenserBlock : public ActorBlock {
public:
    static const int FACING_MASK;
    static const int TRIGGER_BIT;

    DispenserBlock(const std::string&, int);
    virtual int getVariant(const Block&) const;
    virtual FacingID getMappedFace(FacingID, const Block&) const;
    virtual const Block& getPlacementBlock(Actor&, const BlockPos&, FacingID, const Vec3&, int) const;
    virtual void onPlace(BlockSource&, const BlockPos&) const;
    virtual void onRemove(BlockSource&, const BlockPos&) const;
    virtual bool use(Player&, const BlockPos&) const;
    virtual bool isInteractiveBlock() const;
    virtual bool isContainerBlock() const;
    virtual ItemInstance getResourceItem(Random&, const Block&, int) const;
    virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
    virtual ItemInstance getSilkTouchItemInstance(const Block&) const;
    virtual void setupRedstoneComponent(BlockSource&, const BlockPos&) const;
    virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
    virtual bool hasComparatorSignal() const;
    virtual int getComparatorSignal(BlockSource&, const BlockPos&, const Block&, FacingID) const;
    virtual void tick(BlockSource&, const BlockPos&, Random&) const;
    virtual int getTickDelay() const;
    static void ejectItem(BlockSource&, const Vec3&, FacingID, const ItemStack&);
protected:
    void ejectItem(BlockSource&, const Vec3&, FacingID, const ItemStack&, Container&, int) const;
    virtual void dispenseFrom(BlockSource&, const BlockPos&) const;
    Vec3 getDispensePosition(BlockSource&, const Vec3&) const;
    FacingID getFacing(const Block&) const;
private:
    void recalcLockDir(BlockSource&, const BlockPos&);
};