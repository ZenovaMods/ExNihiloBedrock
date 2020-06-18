#pragma once

#include "Random.h"
#include "BlockSourceListener.h"
#include "IWorldRegistriesProvider.h"

class Spawner;
class ActorInfoRegistry;

class Level : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler0[0x168];
    std::shared_ptr<ActorInfoRegistry> mActorInfoRegistry;  // 0x178
    char filler1[0x598];                                    // 0x188
    std::unique_ptr<Spawner> mMobSpawner;                   // 0x720
    char filler2[0x1D0];                                    // 0x8E8
    Random mRandom;                                         // 0x8F8
    char filler3[0xA44];                                    // 0x1D08
    bool mIsClientSide;                                     // 0x1D10


public:
    ActorInfoRegistry* getActorInfoRegistry() {
        return mActorInfoRegistry.get();
    }
    bool isClientSide() const {
        return mIsClientSide;
    }
    Random& getRandom() {
        return mRandom;
    }
    Spawner& getSpawner() const {
        return *mMobSpawner;
    }
};