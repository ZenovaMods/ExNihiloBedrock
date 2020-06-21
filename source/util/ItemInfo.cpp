#include "ItemInfo.h"

#include <sstream>

#include "minecraft/item/ItemStack.h"
#include "minecraft/item/Item.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/block/Block.h"

#include "StringUtils.h"

ItemInfo* ItemInfo::getItemInfoFromStack(ItemStackBase* stack) {
	return new ItemInfo(stack);
}

ItemInfo::ItemInfo(ItemStackBase* stack) {
	item = stack == NULL ? NULL : stack->getItem();
	meta = stack == NULL ? -1 : stack->getAuxValue();
}

ItemInfo::ItemInfo(BlockLegacy* block, int blockMeta) {
	item = ItemRegistry::getItem(*block).get();
	meta = block == NULL ? -1 : blockMeta;
}

ItemInfo::ItemInfo(const std::string& string) {
	item = ItemRegistry::lookupByName(meta, string).get();
}

ItemInfo::ItemInfo(const Block* block) {
	item = block == NULL ? NULL : ItemRegistry::getItem(*block).get();
	meta = block == NULL ? -1 : block->getDataDEPRECATED();
}

std::string ItemInfo::toString() {
	std::stringstream stm;
	stm << item->getCommandName();
	stm << (meta == -1 ? "" : (":" + meta));
	std::string ret;
	stm >> ret;
	return ret;
}

ItemInstance* ItemInfo::getItemStack() {
	return item == NULL ? NULL : new ItemInstance(*item, 1, meta == -1 ? 0 : meta);
}

/*CompoundTag* ItemInfo::writeToNBT(CompoundTag* tag) {
	tag->putString("item", item->getCommandName());
	tag->putInt("meta", meta);

	return tag;
}

ItemInfo* ItemInfo::readFromNBT(CompoundTag* tag) {
	Item* item_ = ItemRegistry::lookupByName(tag->getString("item"));
	int meta_ = tag->getInt("meta");

	return new ItemInfo(new ItemStackBase(*item_, 1, meta_));
}*/

int ItemInfo::hashCode() {
	return 41; // todo
}

bool ItemInfo::equals(ItemInfo* info) {

	if (item == NULL || info->item == NULL)
		return false;

	if (meta == -1 || info->meta == -1)
		return item == info->item;

	return  meta == info->meta && item == info->item;
}