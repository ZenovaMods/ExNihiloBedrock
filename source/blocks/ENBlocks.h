#pragma once

#include <vector>

#include "minecraft/SharedPtr.h"

class BlockLegacy;
namespace Json { class Value; }

class ENBlocks {
public:
	static WeakPtr<BlockLegacy> dust;
	static WeakPtr<BlockLegacy> netherrackCrushed;
	static WeakPtr<BlockLegacy> endstoneCrushed;

	static void init();
	static void initBlockItems();
	static void initGraphics(std::vector<Json::Value>&);
	static void initCreativeBlocksCallback();
};