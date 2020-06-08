#pragma once

class Block;
class BlockPos;
class CompoundTag;

class BlockLegacy {
public:
    virtual ~BlockLegacy();
    Block& getDefaultState() const;
};