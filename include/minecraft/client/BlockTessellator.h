#pragma once

#include "TextureUVCoordinateSet.h"
#include "MaterialPtr.h"
#include "Mesh.h"
#include "BlockShape.h"
#include "../block/Block.h"

struct BlockTessellatorBlockInWorld {
    const Block* block;
    BlockPos pos;
    BlockRenderLayer layer;
    const void* blockActor;
};

class Tessellator;

class BlockTessellatorCache {
public:
    BlockPos mPos;
    BlockSource& mRegion;
    char filler[0x4267C];

    void reset(BlockSource&, const BlockPos&);
    BrightnessPair getLightColor(const BlockPos&);
};

class BlockOccluder {
public:
    BlockOccluder(BlockTessellatorCache&, const Block&, const BlockPos&, const AABB&, const std::vector<FacingID>&, bool);
};

class BlockTessellator {
public:
    bool mNoExtraData;
    bool mUseNormals;
    BlockSource& mRegion;
    TextureUVCoordinateSet mForcedUV;
    bool mUseForcedUV;
    bool mBool4;
    bool mBool5;
    BlockRenderLayer mRenderLayer;
    bool mNoLighting;
    bool mBool6;
    bool mBool7;
    Color mColor;
    char mFiller1[0x70];
    BrightnessPair mLightTexturePositions;
    int mIdk;
    int mFlipFace[6];
    char mFiller2[0x44C];
    mce::MaterialPtr mItemMaterial;
    AABB mBounds;
    bool mHasBounds;
    const Block* mBlock;
    BlockPos mPos;
    char mFiller3[0x44];
    std::unordered_map<BlockTessellatorBlockInWorld, mce::Mesh> mBlockInWorldCache;
    BlockTessellatorCache mCache;
    char mFiller4[0x548];
    
    BlockTessellator(BlockSource*);
    bool tessellateInWorld(Tessellator&, const Block&, const BlockPos&, void*);
    bool tessellateBlockInWorld(Tessellator&, const Block&, const BlockPos&);
    bool tessellateBlockInWorldWithAmbienceOcclusion(Tessellator&, const Block&, BlockPos, const Color&, BlockOccluder*, int);
    bool tessellateExtraDataInWorld(Tessellator&, const Block&, const BlockPos&);

    void tessellateFaceDown(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
    void tessellateFaceUp(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
    void tessellateNorth(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
    void tessellateSouth(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
    void tessellateWest(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
    void tessellateEast(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);

    mce::Mesh& getMeshForBlockInWorld(Tessellator&, const Block&, BlockPos&, BlockRenderLayer, const void*, bool);
    BrightnessPair getLightColor(const BlockPos&);
    bool canRender(BlockShape);
    void reset();

    const AABB& getCurrentShape();

    void setCurrentShape(const AABB& shape) {
        mHasBounds = true;
        mBounds = shape;
    }

    void unsetCurrentShape() {
        mHasBounds = false;
        mBounds = AABB();
    }
};