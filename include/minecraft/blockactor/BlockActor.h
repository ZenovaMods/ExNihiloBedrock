#pragma once

#include <map>

#include "../actor/ActorTerrainInterlockData.h"
#include "../block/BlockActorRendererId.h"
#include "../util/AABB.h"
#include "../world/BlockPos.h"
#include "BlockActorType.h"

class Block;
class BlockSource;
class CompoundTag;
class Container;
class DataLoadHelper;
class Level;
class LevelChunk;
class Packet;
class PistonBlockActor;
class UIProfanityContext;

class BlockActor {
public:
    int mTickCount;
protected:
    const Block* mBlock;
    float mDestroyTimer;
    Vec3 mDestroyDirection;
    float mDestroyProgress;
    BlockPos mPosition;
    AABB mBB;
    const BlockActorType mType;
    BlockActorRendererId mRendererId;
    std::string mCustomName;
    std::string mFilteredCustomName;
    int mRepairCost;
    bool mClientSideOnly;
    bool mIsMovable;
    bool mSaveCustomName;
    bool mCanRenderCustomName;
    const float signShadowRadius;
    ActorTerrainInterlockData mTerrainInterlockData;
private:
    bool mChanged;

public:
    static void setId(BlockActorType, const std::string&);
    static void initBlockEntities();
    BlockActor(BlockActorType, const BlockPos&, const std::string&);
    virtual ~BlockActor();
    virtual void load(Level&, const CompoundTag&, DataLoadHelper&);
    virtual bool save(CompoundTag&) const;
    virtual bool saveItemInstanceData(CompoundTag&);
    virtual void saveBlockData(CompoundTag&, BlockSource&) const;
    virtual void loadBlockData(const CompoundTag&, BlockSource&, DataLoadHelper&);
    virtual void onCustomTagLoadDone(BlockSource&);
    virtual void tick(BlockSource&);
    virtual bool isFinished();
    virtual void onChanged(BlockSource&);
    virtual bool isMovable(BlockSource&);
    virtual bool isCustomNameSaved();
    virtual std::unique_ptr<Packet> getUpdatePacket(BlockSource&);
    virtual void onPlace(BlockSource&);
    virtual void onMove();
    virtual void onRemoved(BlockSource&);
    virtual void triggerEvent(int, int);
    virtual void clearCache();
    virtual void onNeighborChanged(BlockSource&, const BlockPos&);
    virtual float getShadowRadius(BlockSource&) const;
    virtual bool hasAlphaLayer() const;
    virtual BlockActor* getCrackEntity(BlockSource&, const BlockPos&);
    virtual void getDebugText(std::vector<std::string>&, const BlockPos&);
    virtual const std::string& getCustomName() const;
    virtual const std::string& getFilteredCustomName(const UIProfanityContext&);
    virtual std::string getName() const;
    virtual std::string getImmersiveReaderText(BlockSource&);
    virtual int getRepairCost() const;
    virtual PistonBlockActor* getOwningPiston(BlockSource&);
    virtual Container* getContainer();
    virtual float getDeletionDelayTimeSeconds() const;
    virtual void onChunkLoaded(LevelChunk&);
    virtual void onChunkUnloaded(LevelChunk&);
    virtual void _onUpdatePacket(const CompoundTag&, BlockSource&);
    virtual bool _playerCanUpdate(const Player&) const;

    void setChanged() { mChanged = true; }
    void setMovable(bool canMove) { mIsMovable = canMove; }
    void setCustomNameSaved(bool saveCustomName) { mSaveCustomName = saveCustomName; }
    bool isType(BlockActorType type) const { return mType == type; }
    const BlockPos& getPosition() const { return mPosition; }
    static bool isType(BlockActor& te, BlockActorType type) { return te.isType(type); }
};