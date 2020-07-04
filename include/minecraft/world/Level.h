#pragma once

#include "../util/Random.h"
#include "BlockSourceListener.h"
#include "IWorldRegistriesProvider.h"
#include "LevelEvent.h"
#include "../actor/ActorFactory.h"
#include "../block/Block.h"

class Spawner;
class ActorInfoRegistry;
class Player;
class Vec3;
class LevelSettings;
class LevelData;
class ProjectileFactory;
class BehaviorFactory;
class BehaviorTreeGroup;
class BlockPalette;
class PlayerEventCoordinator;
class ServerPlayerEventCoordinator;
class ClientPlayerEventCoordinator;
class ActorEventCoordinator;
class ClientLevelEventCoordinator;
class ServerLevelEventCoordinator;
class BlockEventCoordinator;
class ItemEventCoordinator;

class Level : public BlockSourceListener, public IWorldRegistriesProvider {
private:
    char filler0[0x168];
    std::shared_ptr<ActorInfoRegistry> mActorInfoRegistry;                          // 0x178
    char filler1[0x598];                                                            // 0x188
    std::unique_ptr<Spawner> mMobSpawner;                                           // 0x720
    std::unique_ptr<ProjectileFactory> mProjectileFactory;                          // 0x728
    std::unique_ptr<BehaviorFactory> mBehaviorFactory;                              // 0x730
    std::unique_ptr<BehaviorTreeGroup> mBehaviorTreeDefinitions;                    // 0x738
    std::unique_ptr<BlockPalette> mGlobalBlockPalette;                              // 0x740
    char filler2[0x1B0];                                                            // 0x8E8
    Random mRandom;                                                                 // 0x8F8
    char filler3[0xA44];                                                            // 0x1D08
    bool mIsClientSide;                                                             // 0x1D10
    char filler4[0x158];                                                            // 0x1E68
    std::unique_ptr<PlayerEventCoordinator> mRemotePlayerEventCoordinator;          // 0x1E70
    std::unique_ptr<ServerPlayerEventCoordinator> mServerPlayerEventCoordinator;    // 0x1E78
    std::unique_ptr<ClientPlayerEventCoordinator> mClientPlayerEventCoordinator;    // 0x1E80
    std::unique_ptr<ActorEventCoordinator> mActorEventCoordinator;                  // 0x1E88
    std::unique_ptr<ClientLevelEventCoordinator> mClientLevelEventCoordinator;      // 0x1E90
    std::unique_ptr<ServerLevelEventCoordinator> mServerLevelEventCoordinator;      // 0x1E98
    std::unique_ptr<BlockEventCoordinator> mBlockEventCoordinator;                  // 0x1EA0
    std::unique_ptr<ItemEventCoordinator> mItemEventCoordinator;                    // 0x1EA8
    char filler5[0xD8];                                                             // 0x1EB0
    ActorFactory mActorFactory;                                                     // 0x1F88


public:
    virtual ~Level();
    virtual bool initialize(const std::string&, const LevelSettings&, LevelData*, const std::string*) { return true; }
    virtual void startLeaveGame() {}
    virtual Actor* addEntity(BlockSource&, std::unique_ptr<Actor>);
    void broadcastLevelEvent(LevelEvent, const Vec3&, int, Player*);
    void broadcastSoundEvent(BlockSource&, LevelSoundEvent, const Vec3&, int, const ActorDefinitionIdentifier&, bool, bool);
    void broadcastDimensionEvent(BlockSource&, LevelEvent, const Vec3&, int, Player*);
    void broadcastDimensionEvent(BlockSource& region, LevelEvent type, const Vec3& pos, const Block& block, Player* except) {
        broadcastDimensionEvent(region, type, pos, block.getRuntimeId(), except);
    }
    ActorInfoRegistry* getActorInfoRegistry() {
        return mActorInfoRegistry.get();
    }
    bool isClientSide() const {
        return mIsClientSide;
    }
    ActorFactory& getActorFactory() {
        return mActorFactory;
    }
    const BlockPalette& getGlobalBlockPalette() const {
        return *mGlobalBlockPalette;
    }
    Random& getRandom() {
        return mRandom;
    }
    Spawner& getSpawner() const {
        return *mMobSpawner;
    }
    ActorEventCoordinator& getActorEventCoordinator() {
        return *mActorEventCoordinator;
    }
    ItemEventCoordinator& getItemEventCoordinator() {
        return *mItemEventCoordinator;
    }
};