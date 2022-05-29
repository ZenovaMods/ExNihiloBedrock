#include "BlockActorInfestingLeaves.h"

#include "minecraft/block/Block.h"
#include "minecraft/block/LeafType.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/util/CompoundTag.h"
#include "minecraft/util/DefaultDataLoadHelper.h"
#include "minecraft/util/Packet.h"
#include "minecraft/world/BlockSource.h"

#include "../blocks/ENBlocks.h"
#include "../blocks/BlockInfestingLeaves.h"

BlockActorInfestingLeaves::BlockActorInfestingLeaves(const BlockPos& pos) : BlockActorInfestedLeaves(BlockActorType::InfestingLeaves, pos, "InfestingLeaves"), progress(0.0f) {
	mRendererId = BlockActorRendererId::TR_INFESTINGLEAVES_RENDERER;
}

void BlockActorInfestingLeaves::load(Level& level, const CompoundTag& tag, DataLoadHelper& dataLoadHelper) {
	BlockActor::load(level, tag, dataLoadHelper);
	if (tag.contains("progress")) {
		progress = tag.getFloat("progress");
	}
}

bool BlockActorInfestingLeaves::save(CompoundTag& tag) const {
	if (BlockActor::save(tag)) {
		tag.putFloat("progress", progress);
		return true;
	}
	return false;
}

void BlockActorInfestingLeaves::tick(BlockSource& region) {
	if (progress < 1.0f) {
		progress += 1.0f / 600; // todo config
		setChanged();

		if (progress > 1.0f) {
			progress = 1.0f;

			region.setBlock(mPosition, BlockInfestingLeaves::getBlockForLeaf(region.getBlock(mPosition)), 3, nullptr);
		}
	}
		
	BlockActorInfestedLeaves::tick(region);
}

std::unique_ptr<Packet> BlockActorInfestingLeaves::getUpdatePacket(BlockSource& region) {
	CompoundTag saveData;
	save(saveData);
	return std::make_unique<BlockActorDataPacket>(mPosition, std::move(saveData));
}

void BlockActorInfestingLeaves::onChanged(BlockSource& region) {
	const BlockPos& pos = getPosition();
	const Block& block = region.getBlock(pos);
	region.fireBlockChanged(pos, 0, block, *block.setState<int>(VanillaStates::UpdateBit, 1), 3, nullptr);
}

void BlockActorInfestingLeaves::_onUpdatePacket(const CompoundTag& data, BlockSource& region) {
	DefaultDataLoadHelper loadHelper;
	load(region.getLevel(), data, loadHelper);
}

int BlockActorInfestingLeaves::getLeafColor(int leafColor) const {
	return Color::average(Color::fromARGB(leafColor), Color::WHITE, progress).toARGB();
}
