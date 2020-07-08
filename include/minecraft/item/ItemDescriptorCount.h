#pragma once

#include "ItemDescriptor.h"

class ItemDescriptorCount : public ItemDescriptor {
    uint16_t mStackSize;

public:
    ItemDescriptorCount() : ItemDescriptor(), mStackSize(0) {}
    ItemDescriptorCount(const ItemDescriptor& descriptor, uint16_t stackSize) : ItemDescriptor(descriptor), mStackSize(stackSize) {}
    ItemDescriptorCount(const Block& block, uint16_t stackSize) : ItemDescriptor(block), mStackSize(stackSize) {}
    ItemDescriptorCount(const BlockLegacy& block, uint16_t stackSize) : ItemDescriptor(block), mStackSize(stackSize) {}
    ItemDescriptorCount(const Item& item, int auxValue, uint16_t stackSize) : ItemDescriptor(item, auxValue), mStackSize(stackSize) {}
    short getStackSize() const { return mStackSize; }
    void setStackSize(short size) { mStackSize = size; }
};