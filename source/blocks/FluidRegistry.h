#pragma once

#include "minecraft/block/BlockLegacy.h"

class Fluid {
public:
	static const std::string FLUID_PREFIX;

	short mId;
	std::string mFluidName;
	std::string mBucketTextureItem;
	int mBucketTextureIndex;
	WeakPtr<BlockLegacy>* mStillBlock;
	WeakPtr<BlockLegacy>* mFlowingBlock;

	Fluid(short id, const std::string& fluidName, const std::string& bucketTexture, int bucketTextureIndex, WeakPtr<BlockLegacy>* stillBlock, WeakPtr<BlockLegacy>* flowingBlock)
		: mId(id), mFluidName(fluidName), mBucketTextureItem(bucketTexture), mBucketTextureIndex(bucketTextureIndex), mStillBlock(stillBlock), mFlowingBlock(flowingBlock) {}

	std::string getUnlocalizedName() {
		return FLUID_PREFIX + mFluidName;
	}
};

inline const std::string Fluid::FLUID_PREFIX = "fluid.";

class FluidRegistry {
public:
	static std::vector<Fluid*> mFluids;

	static void registerFluid(const std::string& fluidName, const std::string& bucketTexture, int bucketTextureIndex, WeakPtr<BlockLegacy>* stillBlock, WeakPtr<BlockLegacy>* flowingBlock) {
		mFluids.push_back(new Fluid((short)mFluids.size(), fluidName, bucketTexture, bucketTextureIndex, stillBlock, flowingBlock));
	}

	static Fluid* getFluidFromBlock(const BlockLegacy& fluidBlock) {
		auto it = std::find_if(mFluids.begin(), mFluids.end(), [&fluidBlock](const Fluid* fluid) { 
			return **fluid->mStillBlock == fluidBlock || **fluid->mFlowingBlock == fluidBlock; 
		});
		if (it != mFluids.end())
			return *it;
		return nullptr;
	}
};

inline std::vector<Fluid*> FluidRegistry::mFluids{};