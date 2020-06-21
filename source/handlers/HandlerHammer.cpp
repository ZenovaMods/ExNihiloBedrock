#include "HandlerHammer.h"

#include <vector>

#include "minecraft/item/ItemStack.h"
#include "minecraft/actor/Player.h"
#include "minecraft/world/Level.h"
#include "minecraft/util/EnchantUtils.h"
#include "minecraft/block/Block.h"

#include "../items/tools/HammerBase.h"
#include "../items/tools/database/HammerDatabase.h"
#include "../registries/HammerRegistry.h"

bool HandlerHammer::hammer(const Block& block, const BlockPos& pos, Player& harvester) {
	if (harvester.getLevel().isClientSide() || &harvester == NULL) // isRemote, valid Player
		return false;

	const ItemStack& held = harvester.getSelectedItem();
		
	if (&held == NULL || held.getItem() == NULL || EnchantUtils::hasEnchant(Enchant::Type::MiningSilkTouch, held) || !HammerDatabase::isHammer(held)) // is item invalid, is silktouching, is not hammer
		return false;

	std::vector<ItemInstance*> rewards = HammerRegistry::getRewardDrops(harvester.getRandom(), &block, ((HammerBase*) held.getItem())->getMiningLevel(held), EnchantUtils::getEnchantLevel(Enchant::Type::MiningLoot, held));

	if (rewards.size() > 0) {
		for(ItemInstance* item : rewards) {
			block.getLegacyBlock().popResource(harvester.getRegion(), pos, *item);
		}
	}
	else {
		return false;
	}

	harvester.causeFoodExhaustion(0.025F);

	return true;
}