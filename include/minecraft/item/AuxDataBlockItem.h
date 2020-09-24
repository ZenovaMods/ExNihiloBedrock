#pragma once

#include "BlockItem.h"

class AuxDataBlockItem : public BlockItem {
    const Block* mParentBlock;

public:
    AuxDataBlockItem(const std::string& nameId, int id, const Block* parentBlock) : BlockItem(nameId, id), mParentBlock(parentBlock) {
        setMaxDamage(0);
        setStackedByData(1);
    }
    virtual int getLevelDataForAuxValue(int) const;
    virtual std::string buildDescriptionId(const ItemDescriptor&, const Unique<CompoundTag>&) const;
};