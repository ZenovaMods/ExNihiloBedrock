#include "BlockInfo.h"

#include <sstream>

#include "minecraft/item/ItemStack.h"
#include "minecraft/item/ItemRegistry.h"
#include "minecraft/block/Block.h"

#include "StringUtils.h"

BlockInfo::BlockInfo(const BlockLegacy* _block, int blockMeta) {
	block = _block == NULL ? NULL : _block;
	meta = _block == NULL ? -1 : blockMeta;
}

BlockInfo::BlockInfo(const Block* _block) {
	block = _block == NULL ? NULL : &_block->getLegacyBlock();
	meta = _block == NULL ? -1 : _block->getDataDEPRECATED();
}

BlockInfo::BlockInfo(ItemStackBase* stack) {
	block = stack == NULL ? NULL : &stack->getBlock()->getLegacyBlock();
	meta = stack == NULL ? -1 : stack->getAuxValue();
}

BlockInfo::BlockInfo(const std::string& string) {
	block = ItemRegistry::lookupByName(meta, string)->getLegacyBlock().get();
}

std::string BlockInfo::toString() {
	std::stringstream stm;
	stm << ItemRegistry::getItem(*block)->getCommandName();
	stm << (meta == -1 ? "" : (":" + meta));
	std::string ret;
	stm >> ret;
	return ret;
}

const Block& BlockInfo::getBlockState() {
	return block->getStateFromLegacyData(meta);
}

/*CompoundTag* BlockInfo::writeToNBT(CompoundTag* tag) {
	tag->putString("block", Util::toLower(block->nameId));
	tag->putInt("meta", meta);

	return tag;
}

BlockInfo* BlockInfo::readFromNBT(CompoundTag* tag) {
	Block* block_ = Block::lookupByName(tag->getString("block"), true);
	int meta_ = tag->getInt("meta");

	return new BlockInfo(block_, meta_);
}*/

int BlockInfo::hashCode() {
	return 37; // todo
}

bool BlockInfo::equals(BlockInfo* info) {

	if (block == NULL || info->block == NULL)
		return false;

	if (meta == -1 || info->meta == -1)
		return block == info->block;

	return  meta == info->meta && block == info->block;
}

bool BlockInfo::areEqual(BlockInfo* block1, BlockInfo* block2) {
	if (block1 == NULL && block2 == NULL)
		return true;

	if (block1 == NULL && block2 != NULL)
		return false;

	if (block1 != NULL && block2 == NULL)
		return false;

	return block1->equals(block2);
}