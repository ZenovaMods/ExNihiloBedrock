#include "ItemDoll.h"

#include "minecraft/item/ItemDescriptor.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/actor/Actor.h"
#include "minecraft/world/Spawner.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/actor/ActorType.h"
#include "minecraft/item/ItemHelper.h"
#include "minecraft/actor/ActorFactory.h"

std::vector<std::string> ItemDoll::names{ "blaze", "enderman" };

ItemDoll::ItemDoll(const std::string& name, int id) : Item(name, id), textureItem() {
	setStackedByData(true);
}

bool ItemDoll::isValidAuxValue(int auxValue) const {
	return auxValue >= 0 && auxValue <= 1;
}

std::string ItemDoll::buildDescriptionId(const ItemDescriptor& itemDescriptor, const std::unique_ptr<CompoundTag>& userData) const {
	return mDescriptionId + "." + names[itemDescriptor.getAuxValue()] + ".name";
}

const TextureUVCoordinateSet& ItemDoll::getIcon(const ItemStackBase& itemStack, int frame, bool isInventoryPane) const {
	return getIconTextureUVSet(textureItem, itemStack.getAuxValue(), 3);
}

Item& ItemDoll::setIcon(const std::string& name, int id) {
	Item::setIcon(name, id);
	textureItem = getTextureItem(name);
	return *this;
}

bool ItemDoll::spawnMob(ItemStack& instance, Actor& entity, const BlockPos& pos) const {
	Zenova::Platform::DebugPause();
	Level& level = entity.getLevel();
	ActorType spawnedType = (instance.getAuxValue() == 0) ? ActorType::Blaze : ActorType::EnderMan;
	auto spawned = level.getActorFactory().createSpawnedEntity({ spawnedType }, &entity, { pos.x + 0.5F, pos.y + 1.0F, pos.z + 0.5F }, Vec2::ZERO);
	if (spawned) {
		Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(spawned));
		if (addedEntity)
			level.getItemEventCoordinator().onItemSpawnedActor(instance, *addedEntity);
	}
	return true;
}
