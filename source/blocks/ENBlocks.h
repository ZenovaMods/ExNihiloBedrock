#pragma once

#include <vector>

#include "minecraft/util/SharedPtr.h"

class BlockDefinitionGroup;
class BlockLegacy;
namespace Json { class Value; }

class ENBlocks {
public:
	static WeakPtr<BlockLegacy> dust;
	static WeakPtr<BlockLegacy> netherrackCrushed;
	static WeakPtr<BlockLegacy> endstoneCrushed;
	static WeakPtr<BlockLegacy> blockWitchwaterStill;
	static WeakPtr<BlockLegacy> blockWitchwaterFlowing;

	static void init(BlockDefinitionGroup*);
	static void initBlockItems();
	static void initGraphics(std::vector<Json::Value>&);
	static void initCreativeBlocks();
};