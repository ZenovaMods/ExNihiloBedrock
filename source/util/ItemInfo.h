#pragma once

#include <string>

class Item;
class Block;
class BlockLegacy;
class CompoundTag;
class ItemStackBase;
class ItemInstance;

class ItemInfo {
private:
	const Item* item;
	int meta;

public:
	static ItemInfo* getItemInfoFromStack(ItemStackBase*);
	
	ItemInfo(ItemStackBase*);
	ItemInfo(BlockLegacy*, int);
	ItemInfo(const std::string&);
	ItemInfo(const Block*);
	
	std::string toString();
	ItemInstance* getItemStack();
	CompoundTag* writeToNBT(CompoundTag*);
	
	static ItemInfo* readFromNBT(CompoundTag*);

	int hashCode();
	bool equals(ItemInfo*);

	const Item* getItem() { return item; }
	int getMeta() { return meta; }
	void setMeta(int newMeta) { meta = newMeta; }
};