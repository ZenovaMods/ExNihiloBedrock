#pragma once

#include "Random.h"
#include "BlockSourceListener.h"
#include "IWorldRegistriesProvider.h"

class Level : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler[2280];  // 0x8E8
    Random mRandom;     // 0x8F8
    char filler2[2628]; // 0x1D08
    bool mIsClientSide; // 0x1D10


public:
    bool isClientSide() const {
        return mIsClientSide;
    }
    Random& getRandom() {
        return mRandom;
    }
};