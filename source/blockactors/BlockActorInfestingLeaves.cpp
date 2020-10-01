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

BlockActorInfestingLeaves::BlockActorInfestingLeaves(const BlockPos& pos) : BlockActorInfestedLeaves(BlockActorType::InfestingLeaves, pos, "InfestingLeaves"), progress(0.0F), leafBlock(nullptr) {
	mRendererId = BlockActorRendererId::TR_INFESTINGLEAVES_RENDERER;
}

void BlockActorInfestingLeaves::load(Level& level, const CompoundTag& tag, DataLoadHelper& dataLoadHelper) {
	BlockActor::load(level, tag, dataLoadHelper);
	if (tag.contains("progress")) {
		progress = tag.getFloat("progress");
	}
	if (tag.contains("leafType")) {
		int leafType = tag.getInt("leafType");
		if (leafType < enum_cast(OldLeafType::_count))
			leafBlock = ENBlocks::infestedLeaves->get()->getDefaultState().setState<int>(*VanillaStates::OldLeafType, leafType);
		else
			leafBlock = ENBlocks::infestedLeaves2->get()->getDefaultState().setState<int>(*VanillaStates::NewLeafType, leafType - enum_cast(OldLeafType::_count));
	}
}

bool BlockActorInfestingLeaves::save(CompoundTag& tag) const {
	if (BlockActor::save(tag)) {
		if (leafBlock != nullptr) {
			int leafType = 0;
			if (leafBlock->hasState(*VanillaStates::OldLeafType))
				leafType = leafBlock->getState<int>(*VanillaStates::OldLeafType);
			else if (leafBlock->hasState(*VanillaStates::NewLeafType))
				leafType = leafBlock->getState<int>(*VanillaStates::NewLeafType) + enum_cast(OldLeafType::_count);
			tag.putInt("leafType", leafType);
		}
		tag.putFloat("progress", progress);
		return true;
	}
	return false;
}

void BlockActorInfestingLeaves::tick(BlockSource& region) {
	if (progress < 1.0F) {
		progress += 1.0F / 600; // todo config
		setChanged();

		if (progress > 1.0F) {
			progress = 1.0F;

			region.setBlock(mPosition, *getLeafBlock(region.getBlock(mPosition)), 3, nullptr);
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
	region.fireBlockChanged(pos, 0, block, *block.setState<int>(*VanillaStates::UpdateBit, 1), 3, nullptr);
}

void BlockActorInfestingLeaves::_onUpdatePacket(const CompoundTag& data, BlockSource& region) {
	DefaultDataLoadHelper loadHelper;
	load(region.getLevel(), data, loadHelper);
}

Color BlockActorInfestingLeaves::getLeafColor(Color& leafColor, BlockSource& region) const {
	return Color::average(leafColor, Color::WHITE, progress);
}

const Block* BlockActorInfestingLeaves::getLeafBlock(const Block& infestingLeaf) const {
	return leafBlock != nullptr ? leafBlock : &BlockInfestingLeaves::getBlockForLeaf(infestingLeaf);
}
