#include "ItemOre.h"

#include "minecraft/item/ItemStack.h"
#include "minecraft/item/ItemDescriptor.h"
#include "minecraft/util/I18n.h"

#include "../../util/StringUtils.h"

const std::vector<std::string> ItemOre::ORE_TYPES = { "orepiece", "orehunk", "oredust", "oreingot" };

ItemOre::ItemOre(const std::string& nameId, int id, Ore* ore) : Item("exnihilo:ore." + nameId, id), registerIngot(ore->getResult() == nullptr), ore(ore), textureItem() {
	setStackedByData(true);
	setCategory(CreativeItemCategory::ITEMS);
}

bool ItemOre::isValidAuxValue(int auxValue) const {
	return auxValue >= 0 && auxValue <= (registerIngot ? 3 : 2);
}

std::string ItemOre::buildDescriptionId(const ItemDescriptor& itemDescriptor, const std::unique_ptr<CompoundTag>& userData) const {
	return StringUtils::capitalize(ore->getName()) + " " + I18n::get(ORE_TYPES[itemDescriptor.getAuxValue()] + ".name");
}

const TextureUVCoordinateSet& ItemOre::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return getIconTextureUVSet(textureItem, itemStack.getAuxValue(), (registerIngot ? 3 : 2));
}

Item& ItemOre::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	textureItem = getTextureItem(name);
	return *this;
}

Color ItemOre::getColor(const std::unique_ptr<CompoundTag>& userData, const ItemDescriptor& instance) const {
	return ore->getColor();
}

bool ItemOre::isTintable() const {
	return true;
}
