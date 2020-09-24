#pragma once

#include "TextureUVCoordinateSet.h"
#include "MaterialPtr.h"
#include "Mesh.h"
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
};

class BlockTessellator {
public:
    bool mBool1;
    bool mBool2;
    BlockSource& mRegion;
    TextureUVCoordinateSet mForcedUV;
    bool mBool3;
    bool mBool4;
    bool mBool5;
    BlockRenderLayer mRenderLayer;
    char mFiller2[0x4F0];
    mce::MaterialPtr mItemMaterial;
    AABB mBounds;
    bool mHasBounds;
    Block& mBlock;
    BlockPos mPos;
    char mFiller3[0x44];
    std::unordered_map<BlockTessellatorBlockInWorld, mce::Mesh> mBlockInWorldCache;
    BlockTessellatorCache mCache;
    char mFiller4[0x548];
    
    BlockTessellator(BlockSource*);
    bool tessellateInWorld(Tessellator&, const Block&, const BlockPos&, void*);
    mce::Mesh& getMeshForBlockInWorld(Tessellator&, const Block&, BlockPos&, BlockRenderLayer, const void*, bool);

};