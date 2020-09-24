#include "BlockActorInfestedLeaves.h"

#include "minecraft/block/Block.h"
#include "minecraft/block/VanillaBlockTypeRegistry.h"
#include "minecraft/world/BlockPos.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Level.h"

#include "../blocks/BlockInfestingLeaves.h"

uint64_t BlockActorInfestedLeaves::tileId = 0;

BlockActorInfestedLeaves::BlockActorInfestedLeaves(BlockActorType type, const BlockPos& pos, const std::string& nameId) : BlockActor(type, pos, nameId), hasNearbyLeaves(true) {
	updateIndex = ++tileId % 40; // todo config
}

BlockActorInfestedLeaves::BlockActorInfestedLeaves(const BlockPos& pos) : BlockActorInfestedLeaves(BlockActorType::InfestedLeaves, pos, "InfestedLeaves") {}

void BlockActorInfestedLeaves::tick(BlockSource& region) {
	// Don't update unless there's leaves nearby, or we haven't checked for leavesUpdateFrequency ticks. And only update on the server
	if (!region.getLevel().isClientSide() && hasNearbyLeaves || mTickCount % 40 == updateIndex) { // todo config
		hasNearbyLeaves = false;

		for (int x = -1; x <= 1; x++) {
			for (int y = -1; y <= 1; y++) {
				for (int z = -1; z <= 1; z++) {
					BlockPos newPos = mPosition + BlockPos(x, y, z);
					const Block& state = region.getBlock(newPos);

					if (&state != nullptr && (state.getLegacyBlock() == **VanillaBlockTypes::mLeaves || state.getLegacyBlock() == **VanillaBlockTypes::mLeaves2)) {
						hasNearbyLeaves = true;

						if (region.getLevel().getRandom().nextFloat() < 0.0015F) { // todo config
							BlockInfestingLeaves::infestLeafBlock(region, newPos);
						}
					}
				}
			}
		}
	}
	BlockActor::tick(region);
}


