#include "ItemResource.h"

#include "ENItems.h"
#include "../blocks/BlockInfestingLeaves.h"

#include "minecraft/actor/Actor.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/item/ItemDescriptor.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/block/VanillaBlockRegistry.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"

const std::string ItemResource::PORCELAIN_CLAY = "porcelain_clay";
const std::string ItemResource::SILKWORM = "silkworm";
const std::string ItemResource::ANCIENT_SPORES = "ancient_spores";
const std::string ItemResource::GRASS_SEEDS = "grass_seeds";
const std::string ItemResource::DOLL_BASE = "doll";

std::string ItemResource::names[6];

ItemResource::ItemResource(const std::string& name, int id) : Item(name, id), textureItem() {
	setStackedByData(true);
	setCategory(CreativeItemCategory::ITEMS);

	names[0] = "removed";
	names[1] = PORCELAIN_CLAY;
	names[2] = SILKWORM;
	names[3] = ANCIENT_SPORES;
	names[4] = GRASS_SEEDS;
	names[5] = DOLL_BASE;
}

bool ItemResource::isValidAuxValue(int auxValue) const {
	return auxValue >= 0 && auxValue <= 5;
}

std::string ItemResource::buildDescriptionId(const ItemDescriptor& itemDescriptor, const std::unique_ptr<CompoundTag>& userData) const {
	return mDescriptionId + "." + names[itemDescriptor.getAuxValue()] + ".name";
}

const TextureUVCoordinateSet& ItemResource::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return getIconTextureUVSet(textureItem, itemStack.getAuxValue(), 5);
}

Item& ItemResource::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	textureItem = getTextureItem(name);
	return *this;
}

bool ItemResource::_useOn(ItemStack& instance, Actor& entity, BlockPos pos, FacingID face, float clickX, float clickY, float clickZ) const {
	short auxValue = instance.getAuxValue();
	if (names[auxValue] == SILKWORM) {
		const BlockLegacy& block = entity.getRegion().getBlock(pos).getLegacyBlock();
		if (&block != NULL && (block == *VanillaBlockTypes::mLeaves || block == *VanillaBlockTypes::mLeaves2)) {
			BlockInfestingLeaves::infestLeafBlock(entity.getRegion(), pos);
			instance.remove(1);
			return true;
		}
	}
	if (names[auxValue] == ANCIENT_SPORES || names[auxValue] == GRASS_SEEDS) {
		const BlockLegacy& block = entity.getRegion().getBlock(pos).getLegacyBlock();
		if (&block != NULL && block == *VanillaBlockTypes::mDirt) {
			Block* transformTo = names[auxValue] == ANCIENT_SPORES ? VanillaBlocks::mMycelium : VanillaBlocks::mGrass;
			entity.getRegion().setBlock(pos, *transformTo, 3, nullptr);
			instance.remove(1);
			return true;
		}
	}

	return false;
}

ItemInstance* ItemResource::getResourceStack(const std::string& name) {
	return getResourceStack(name, 1);
}

ItemInstance* ItemResource::getResourceStack(const std::string& name, int quantity) {
	for (int i = 0; i < 6; i++) {
		if (names[i] == name)
			return new ItemInstance(*ENItems::resources, quantity, i);
	}

	return nullptr;
}