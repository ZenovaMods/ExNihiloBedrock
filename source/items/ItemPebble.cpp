#include "ItemPebble.h"

#include "ENItems.h"

#include "minecraft/actor/ActorDefinitionIdentifier.h"
#include "minecraft/actor/ActorType.h"
#include "minecraft/item/ItemHelper.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/item/ItemDescriptor.h"
#include "minecraft/actor/Player.h"
#include "minecraft/world/Spawner.h"
#include "minecraft/util/Vec3.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/util/Facing.h"
#include "minecraft/world/Container.h"

std::vector<std::string> ItemPebble::names { "stone", "granite", "diorite", "andesite" };

ItemPebble::ItemPebble(const std::string& name, int id) : Item(name, id), textureItem() {
	setStackedByData(true);
	setCategory(CreativeItemCategory::ITEMS);
}

bool ItemPebble::isThrowable() const {
	return true;
}

bool ItemPebble::isValidAuxValue(int auxValue) const {
	return auxValue >= 0 && auxValue <= 3;
}

ItemStack& ItemPebble::use(ItemStack& instance, Player& player) const {
	Level& level = player.getLevel();
	short auxValue = instance.getAuxValue();
	player.useItem(instance, ItemUseMethod::Throw, true);
	player.swing();
	if (!level.isClientSide()) {
		player.playSynchronizedSound(LevelSoundEvent::Throw, player.getAttachPos(ActorLocation::DropAttachPoint, 0.0), -1, false);
		Actor* pebble = level.getSpawner().spawnProjectile(player.getRegion(), { "exnihilo:pebble" }, &player, player.getPos(), Vec3::ZERO);
		if (pebble)
			pebble->setAuxValue(auxValue);
	}
	return instance;
}

bool ItemPebble::dispense(BlockSource& region, Container& container, int slot, const Vec3& pos, FacingID face) const {
	Vec3 direction = { (float)Facing::STEP_X[face], (float)Facing::STEP_Y[face] + 0.1f, (float)Facing::STEP_Z[face] };
	Level& level = region.getLevel();
	if (!level.isClientSide()) {
		Actor* pebble = level.getSpawner().spawnProjectile(region, { "exnihilo:pebble" }, nullptr, pos, direction);
		if (pebble) {
			pebble->setAuxValue(container.getItem(slot).getAuxValue());
			container.removeItem(slot, 1);
			level.broadcastLevelEvent(LevelEvent::SoundLaunch, pos, 0x13332, nullptr);
			return true;
		}
	}
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
	return new ItemInstance(*ENItems::pebbles, 1, (int)meta);
}