#include "ItemSeedBase.h"

#include "minecraft/ItemDescriptor.h"
#include "minecraft/ItemStack.h"

const std::string ItemSeedBase::OAK = "Oak";
const std::string ItemSeedBase::SPRUCE = "Spruce";
const std::string ItemSeedBase::BIRCH = "Birch";
const std::string ItemSeedBase::JUNGLE = "Jungle";
const std::string ItemSeedBase::ACACIA = "Acacia";
const std::string ItemSeedBase::DARK_OAK = "DarkOak";

std::string ItemSeedBase::names[6] = { OAK, SPRUCE, BIRCH, JUNGLE, ACACIA, DARK_OAK };

ItemSeedBase::ItemSeedBase(const std::string& name, int id, const Block& block, bool subItems) : BlockPlanterItem(name, id, block, false), textureItem(), hasSubItems(subItems) {
	setStackedByData(hasSubItems);
}

bool ItemSeedBase::isValidAuxValue(int auxValue) const {
	return hasSubItems ? auxValue >= 0 && auxValue <= 5 : true;
}

std::string ItemSeedBase::buildDescriptionId(const ItemDescriptor& itemDescriptor, const std::unique_ptr<CompoundTag>& userData) const {
	return hasSubItems ? mDescriptionId + names[itemDescriptor.getAuxValue()] + ".name" : Item::buildDescriptionId(itemDescriptor, userData);
}

const TextureUVCoordinateSet& ItemSeedBase::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return hasSubItems ? getIconTextureUVSet(textureItem, itemStack.getAuxValue(), 5) : Item::getIcon(itemStack, frame, isInventoryPane);
}

Item& ItemSeedBase::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	if (hasSubItems) {
		textureItem = getTextureItem(name);
		return *this;
	}
}