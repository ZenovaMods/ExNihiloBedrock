#pragma once

#include "Item.h"
#include "../actor/ActorType.h"

enum class BucketFillType : short {
    Unknown = -1,
    Empty,
    Milk,
    Fish,
    Salmon,
    Tropicalfish,
    Pufferfish,
    Water = 8,
    Lava = 10
};

class BucketItem : public Item {
public:
    static const int DRINK_DURATION = 32;
private:
    TextureUVCoordinateSet m_uvBucketEmpty;
    TextureUVCoordinateSet m_uvBucketLava;
    TextureUVCoordinateSet m_uvBucketMilk;
    TextureUVCoordinateSet m_uvBucketWater;
    TextureUVCoordinateSet m_uvBucketFish;
    TextureUVCoordinateSet m_uvBucketSalmon;
    TextureUVCoordinateSet m_uvBucketTropical;
    TextureUVCoordinateSet m_uvBucketPuffer;

public:
    BucketItem(const std::string&, int);
    virtual Item& setIcon(const std::string&, int);
    virtual byte getMaxStackSize(const ItemDescriptor&) const;
    virtual ItemStack& use(ItemStack&, Player&) const;
    virtual void releaseUsing(ItemStack&, Player*, int) const;
    virtual ItemUseMethod useTimeDepleted(ItemStack&, Level*, Player*) const;
    virtual bool uniqueAuxValues() const;
    virtual bool dispense(BlockSource&, Container&, int, const Vec3&, FacingID) const;
    virtual bool isLiquidClipItem(int) const;
    virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
    virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
    virtual bool isEmissive(int) const;
    virtual bool isValidAuxValue(int) const;
    virtual bool isDestructive(int) const;
    virtual std::string getAuxValuesDescription() const;
    bool _takeLiquid(ItemStack&, Actor&, const BlockPos&) const;
private:
    virtual bool _useOn(ItemStack&, Actor&, BlockPos, FacingID, float, float, float) const;
    bool _emptyBucket(BlockSource&, const Block&, const BlockPos&, Actor*, const ItemStack&, FacingID) const;
    bool _canEmptyBucketIntoBlock(const Block&, const Block&) const;
    BucketFillType _getBucketFillType(const Block&) const;
    const BlockLegacy* _tryGetBlock(BucketFillType) const;
    bool isBlockFillType(BucketFillType) const;
};