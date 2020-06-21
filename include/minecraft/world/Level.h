#pragma once

#include "../util/Random.h"
#include "BlockSourceListener.h"
#include "IWorldRegistriesProvider.h"
#include "LevelEvent.h"
#include "ItemEventCoordinator.h"
#include "ActorFactory.h"

class Spawner;
class ActorInfoRegistry;
class Player;
class Vec3;
class LevelSettings;
class LevelData;

class Level : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler0[0x168];
    std::shared_ptr<ActorInfoRegistry> mActorInfoRegistry;          // 0x178
    char filler1[0x598];                                            // 0x188
    std::unique_ptr<Spawner> mMobSpawner;                           // 0x720
    char filler2[0x1D0];                                            // 0x8E8
    Random mRandom;                                                 // 0x8F8
    char filler3[0xA44];                                            // 0x1D08
    bool mIsClientSide;                                             // 0x1D10
    char filler4[0x190];                                            // 0x1EA0
    std::unique_ptr<ItemEventCoordinator> mItemEventCoordinator;    // 0x1EA8
    char filler5[0xD8];                                             // 0x1EB0
    ActorFactory mActorFactory;                                     // 0x1F88


public:
    virtual ~Level();
    virtual bool initialize(const std::string&, const LevelSettings&, LevelData*, const std::string*) { return true; }
    virtual void startLeaveGame() {}
    virtual Actor* addEntity(BlockSource&, std::unique_ptr<Actor>);
    void broadcastLevelEvent(LevelEvent, const Vec3&, int, Player*);
    ActorInfoRegistry* getActorInfoRegistry() {
        return mActorInfoRegistry.get();
    }
    bool isClientSide() const {
        return mIsClientSide;
    }
    ActorFactory& getActorFactory() {
        return mActorFactory;
    }
    Random& getRandom() {
        return mRandom;
    }
    Spawner& getSpawner() const {
        return *mMobSpawner;
    }
    ItemEventCoordinator& getItemEventCoordinator() {
        return *mItemEventCoordinator;
    }
};