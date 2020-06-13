#pragma once

#include <string>

struct LootComponentDescription;

class Block;
class BlockLegacy;
class BlockPos;
class BlockSource;

class LootComponent {
private:
    BlockLegacy& mBlockLegacy;
    std::string mLootTable;

public:
    LootComponent(BlockLegacy&);
    void init(const LootComponentDescription&);
    void spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
};