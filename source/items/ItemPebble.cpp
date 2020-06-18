#include "ItemPebble.h"

#include "ENItems.h"

#include "minecraft/ActorDefinitionIdentifier.h"
#include "minecraft/ActorType.h"
#include "minecraft/ItemHelper.h"
#include "minecraft/ItemStack.h"
#include "minecraft/ItemDescriptor.h"
#include "minecraft/LevelEvent.h"
#include "minecraft/Player.h"
#include "minecraft/Spawner.h"
#include "minecraft/Vec3.h"

std::vector<std::string> ItemPebble::names { "stone", "granite", "diorite", "andesite" };

ItemPebble::ItemPebble(const std::string& name, int id) : Item(name, id), textureItem() {
	setStackedByData(true);
}

bool ItemPebble::isThrowable() const {
	return true;
}

bool ItemPebble::isValidAuxValue(int auxValue) const {
	return auxValue >= 0 && auxValue <= 3;
}

ItemStack& ItemPebble::use(ItemStack& instance, Player& player) const {
	Level& level = player.getLevel();
	player.useItem(instance, ItemUseMethod::Throw, true);
	player.swing();
	if (!level.isClientSide()) {
		player.playSynchronizedSound(LevelSoundEvent::Throw, player.getAttachPos(ActorLocation::DropAttachPoint, 0.0), -1, false);
		Actor* pebble = level.getSpawner().spawnProjectile(player.getRegion(), ActorDefinitionIdentifier("exnihilo:pebble"), &player, player.getPos(), Vec3::ZERO);
		if (pebble)
			pebble->getEntityData().define(0x24, instance.getAuxValue());
	}
	return instance;
}

bool ItemPebble::dispense(BlockSource&, Container&, int, const Vec3&, unsigned char) const {
	return false;
}

std::string ItemPebble::buildDescriptionId(const ItemDescriptor& itemDescriptor, const std::unique_ptr<CompoundTag>& userData) const {
	return mDescriptionId + "." + names[itemDescriptor.getAuxValue()] + ".name";
}

const TextureUVCoordinateSet& ItemPebble::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return getIconTextureUVSet(textureItem, itemStack.getAuxValue(), 3);
}

Item& ItemPebble::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	textureItem = getTextureItem(name);
	return *this;
}

ItemInstance* ItemPebble::getPebbleStack(const std::string& name) {
	auto meta = std::distance(names.begin(), std::find(names.begin(), names.end(), name));
	return new ItemInstance(*ENItems::pebbles, 1, meta);
}