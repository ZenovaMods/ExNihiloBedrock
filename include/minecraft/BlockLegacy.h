#pragma once

class Block;
class BlockPos;
class CompoundTag;

class BlockLegacy {
public:
    virtual ~BlockLegacy();
    Block& getDefaultState() const;
    bool operator==(const BlockLegacy& rhs) const {
        return this == &rhs;
    }
    bool operator!=(const BlockLegacy& rhs) const {
        return !(*this == rhs);
    }
};