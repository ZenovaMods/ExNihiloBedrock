#pragma once

class Block;
class BlockLegacy;

class BlockPalette {
public:
    const Block& switchBlock(const Block&, const BlockLegacy&) const;
};