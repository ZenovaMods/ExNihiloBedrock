#pragma once

#include <string>

class Block;
class BlockLegacy;
class CompoundTag;
class ItemStackBase;

class BlockInfo {
private:
	const BlockLegacy* block;
	int meta;

public:
	BlockInfo(const BlockLegacy*, int);
	BlockInfo(const Block*);
	BlockInfo(ItemStackBase*);
	BlockInfo(const std::string&);
	
	std::string toString();
	const Block& getBlockState();
	CompoundTag* writeToNBT(CompoundTag*);
	
	static BlockInfo* readFromNBT(CompoundTag*);

	int hashCode();
	bool equals(BlockInfo*);

	static bool areEqual(BlockInfo*, BlockInfo*);

	const BlockLegacy* getBlock() { return block; }
	int getMeta() { return meta; }
	void setMeta(int newMeta) { meta = newMeta; }
};