#pragma once

#include "BlockLegacy.h"

class HeavyBlock : public BlockLegacy {
public:
    HeavyBlock(const std::string& nameId, int id, const Material& material) : BlockLegacy(nameId, id, material) {
        mCanSlide = true;
        mHeavy = true;
    }
    virtual void onPlace(BlockSource&, const BlockPos&) const;
    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual void tick(BlockSource&, const BlockPos&, Random&) const;
    virtual void animateTick(BlockSource&, const BlockPos&, Random&) const;
    virtual Color getDustColor(const Block&) const = 0;
    virtual std::string getDustParticleName(const Block&) const = 0;
    virtual bool falling() const;
    virtual void onLand(BlockSource&, const BlockPos&) const;
    virtual bool isFreeToFall(BlockSource&, const BlockPos&) const;
protected:
    virtual void startFalling(BlockSource&, const BlockPos&, const Block*, bool) const;
};