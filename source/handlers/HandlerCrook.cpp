#include "HandlerCrook.h"

#include <vector>

#include "minecraft/item/ItemStack.h"
#include "minecraft/actor/Player.h"
#include "minecraft/world/Level.h"
#include "minecraft/util/EnchantUtils.h"
#include "minecraft/block/Block.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"

#include "../items/tools/database/CrookDatabase.h"
#include "../registries/CrookRegistry.h"
#include "../registries/types/CrookReward.h"

bool HandlerCrook::crook(const Block& block, const BlockPos& pos, Player& harvester) {
	if (harvester.getLevel().isClientSide() || &harvester == NULL) // isRemote, valid Player
		return false;

	const ItemStack& held = harvester.getSelectedItem();
		
	if (&held == NULL || held.getItem() == NULL || EnchantUtils::hasEnchant(Enchant::Type::MiningSilkTouch, held) || !CrookDatabase::isCrook(held)) // is item invalid, is silktouching, is not crook
		return false;

	int fortune = EnchantUtils::getEnchantLevel(Enchant::Type::MiningLoot, held);

	std::vector<CrookReward*> rewards = CrookRegistry::getRewards(&block);
	if (rewards.size() > 0) {
		for(CrookReward* reward : rewards) {
			if (harvester.getRandom().nextFloat() <= reward->getChance() + (reward->getFortuneChance() * fortune)) {
				block.getLegacyBlock().popResource(harvester.getRegion(), pos, reward->getStack()->clone());
			}
		}
	}
	const BlockLegacy& legacyBlock = block.getLegacyBlock();
	if (legacyBlock == *VanillaBlockTypes::mLeaves || legacyBlock == *VanillaBlockTypes::mLeaves2) { //Simulate vanilla drops
		for (int i = 0 ; i < 4; i++) { // todo config
			legacyBlock.spawnResources(harvester.getRegion(), pos, block, 1.0f, fortune);
		}
	}
	else {
		return false;
	}

	harvester.causeFoodExhaustion(0.025F);

	return true;
}