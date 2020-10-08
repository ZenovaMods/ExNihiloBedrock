#pragma once

#include <vector>
#include <string>

#include "minecraft/util/SharedPtr.h"

class BlockLegacy;
namespace Json { class Value; }

class ENBlocks {
public:
	static WeakPtr<BlockLegacy>* dust;
	static WeakPtr<BlockLegacy>* netherrackCrushed;
	static WeakPtr<BlockLegacy>* endstoneCrushed;
	static WeakPtr<BlockLegacy>* andesiteCrushed;
	static WeakPtr<BlockLegacy>* dioriteCrushed;
	static WeakPtr<BlockLegacy>* graniteCrushed;
	static WeakPtr<BlockLegacy>* barrelWood;
	static WeakPtr<BlockLegacy>* barrelStone;
	static WeakPtr<BlockLegacy>* infestingLeaves;
	static WeakPtr<BlockLegacy>* infestingLeaves2;
	static WeakPtr<BlockLegacy>* infestedLeaves;
	static WeakPtr<BlockLegacy>* infestedLeaves2;
	static WeakPtr<BlockLegacy>* blockWitchwaterStill;
	static WeakPtr<BlockLegacy>* blockWitchwaterFlowing;

	static void init();
	static void initBlockItems();
	static void initCreativeBlocks();
};