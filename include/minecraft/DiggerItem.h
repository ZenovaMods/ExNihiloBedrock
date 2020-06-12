#pragma once

#include <set>

#include "Item.h"

class DiggerItem : public Item {
private:
    typedef std::vector<Block const*> BlockList;

protected:
    float mSpeed;
    const Item::Tier& mTier;
private:
    int mAttackDamage;
    BlockList mBlocks;
    std::set<BlockLegacy const*> m_bBlocks;

public:
    virtual ~DiggerItem();
    virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
    virtual bool mineBlock(ItemStack&, const Block&, int, int, int, Actor*) const;
    virtual int getAttackDamage() const;
    virtual bool isHandEquipped() const;
    virtual int getEnchantValue() const;
    virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&) const;
    virtual void appendFormattedHovertext(const ItemStackBase&, Level&, std::string&, const bool) const;
protected:
    DiggerItem(const std::string&, int, int, const Item::Tier&, const BlockList&);
};