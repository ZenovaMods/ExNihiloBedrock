#pragma once

#include "Random.h"
#include "BlockSourceListener.h"
#include "IWorldRegistriesProvider.h"

class Level : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler[2280];  // 0x8E8
    Random mRandom;     // 0x8F8

public:
    Random& getRandom() {
        return mRandom;
    }
};