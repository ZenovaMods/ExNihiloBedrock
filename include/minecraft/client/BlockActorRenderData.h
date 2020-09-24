#pragma once

class Block;
class BlockActor;
class BlockSource;
class Vec3;
namespace mce { class MaterialPtr; }

class BlockActorRenderData {
public:
	BlockSource& mRegion;
	BlockActor& mBlockActor;
	Block& mBlock;
	Vec3& mPos;
	mce::MaterialPtr& mMaterial;

	BlockSource& getRegion() { return mRegion; }
	BlockActor& getBlockActor() { return mBlockActor; }
	Block& getBlock() { return mBlock; }
	Vec3& getPosition() { return mPos; }
	mce::MaterialPtr& getMaterial() { return mMaterial; }
};