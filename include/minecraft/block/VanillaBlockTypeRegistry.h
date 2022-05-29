#pragma once

#include "../util/SharedPtr.h"
#include "BlockLegacy.h"


namespace VanillaBlockTypes {
	extern WeakPtr<BlockLegacy>& mGrass;
	extern WeakPtr<BlockLegacy>& mDirt;
	extern WeakPtr<BlockLegacy>& mCobblestone;
	extern WeakPtr<BlockLegacy>& mSand;
	extern WeakPtr<BlockLegacy>& mGravel;
	extern WeakPtr<BlockLegacy>& mLeaves;
	extern WeakPtr<BlockLegacy>& mMycelium;
	extern WeakPtr<BlockLegacy>& mLeaves2;
	extern WeakPtr<BlockLegacy>& mTopSnow;

	extern void registerBlocks();
}