#pragma once

#include <functional>
#include <string>
#include <vector>

#include "AABB.h"
#include "BlockState.h"
#include "CreativeItemCategory.h"
#include "Color.h"
#include "LootComponent.h"
#include "Mutex.h"
#include "Version.h"
#include "Material.h"
#include "SharedPtr.h"
#include "BlockTypeRegistry.h"

class Block;
class BlockPos;
class BlockSource;
class CompoundTag;
class Container;
class ItemInstance;
class Vec3;
class Actor;
class Mob;
class Player;
class Random;
class HitResult;
class SpawnConditions;
class MobSpawnerData;
class Flip;
class ItemActor;
struct ActorBlockSyncMessage;

typedef std::function<const Block& (const BlockPos&)> GetBlockFunction;
typedef unsigned short DataID;
typedef unsigned char FacingID;
typedef unsigned char Brightness;
typedef unsigned short NewBlockID;

enum class FertilizerType : unsigned char;
enum class BlockActorType : int;
enum class BlockRenderLayer : unsigned int;
enum class BlockSupportType : int;
enum class BlockProperty : unsigned long long {
    None,
    Stair,
    HalfSlab,
    Hopper = 4,
    TopSnow = 8,
    FenceGate = 16,
    Leaf = 32,
    ThinConnects2D = 64,
    Connects2D = 128,
    Carpet = 256,
    Button = 512,
    Door = 1024,
    Portal = 2048,
    Heavy = 4096,
    Snow = 8192,
    Trap = 16384,
    Sign = 32768,
    Walkable = 65536,
    PressurePlate = 131072,
    PistonBlockGrabber = 262144,
    TopSolidBlocking = 524288,
    SolidBlocking = 1048576,
    CubeShaped = 2097152,
    Power_NO = 4194304,
    Power_BlockDown = 8388608,
    Immovable = 16777216,
    BreakOnPush = 33554432,
    Piston = 67108864,
    InfiniBurn = 134217728,
    RequiresWorldBuilder = 268435456,
    CausesDamage = 536870912,
    BreaksWhenFallenOnByHeavy = 1073741824,
    OnlyPistonPush = 2147483648,
    Liquid = 4294967296,
    CanBeBuiltOver = 8589934592,
    SnowRecoverable = 17179869184,
    Scaffolding = 34359738368,
    CanSupportCenterHangingBlock = 68719476736,
    BreaksWhenHitByArrow = 137438953472,
    Unwalkable = 274877906944,
    Impenetrable = 549755813888,
    Hollow = 1099511627776,
    OperatorBlock = 2199023255552,
    SupportedByFlowerPot = 4398046511104,
    PreventsJumping = 8796093022208,
    ContainsHoney = 17592186044416,
    Slime = 35184372088832
};

class BlockLegacy {
public:
    std::string mDescriptionId;
    std::string mRawNameId;
    std::string mNamespace;
    std::string mFullName;
    bool mFancy;
    BlockRenderLayer mRenderLayer;
    bool mRenderLayerCanRenderAsOpaque;
    BlockProperty mProperties;
    BlockActorType mBlockEntityType;
    bool mAnimatedTexture;
    float mBrightnessGamma;
    float mThickness;
    bool mCanSlide;
    bool mCanInstatick;
    bool mIsInteraction;
    float mGravity;
    const Material& mMaterial;
    Color mMapColor;
    float mFriction;
    bool mHeavy;
    float mParticleQuantityScalar;
    float mDestroySpeed;
    float mExplosionResistance;
    CreativeItemCategory mCreativeCategory;
    bool mAllowsRunes;
    bool mCanBeBrokenFromFalling;
    bool mSolid;
    bool mPushesOutItems;
    bool mIgnoreBlockForInsideCubeRenderer;
    bool mIsTrapdoor;
    bool mIsDoor;
    float mTranslucency;
    Brightness mLightBlock;
    Brightness mLightEmission;
    bool mShouldRandomTick;
    bool mShouldRandomTickExtraLayer;
    int mFlameOdds;
    int mBurnOdds;
    bool mIsMobPiece;
    bool mCanBeExtraBlock;
    bool mCanPropagateBrightness;
private:
    NewBlockID mID;
    BaseGameVersion mMinRequiredBaseGameVersion;
    bool mExperimental;
    bool mIsVanilla;
public:
    std::unique_ptr<LootComponent> mLootComponent;
private:
    AABB mVisualShape;
    unsigned int mBitsUsed;
    unsigned int mTotalBitsUsed;
    std::array<ItemStateInstance, 105> mStates;
    std::vector<std::unique_ptr<Block>> mBlockPermutations;
    const Block* mDefaultState;
    Bedrock::Threading::SharedMutex mLegacyDataLookupTableMutex;
    std::vector<long> mLegacyDataLookupTable;

public:
    BlockLegacy(const std::string&, int, const Material&);
    virtual ~BlockLegacy();
    virtual void tick(BlockSource&, const BlockPos&, Random&) const;
    virtual const Block& getStateFromLegacyData(DataID) const;
    virtual const Block* getNextBlockPermutation(const Block&) const;
    virtual bool getCollisionShape(AABB&, const Block&, BlockSource&, const BlockPos&, Actor*) const;
    virtual bool isObstructingChests(BlockSource&, const BlockPos&) const;
    virtual Vec3 randomlyModifyPosition(const BlockPos&, int32_t&) const;
    virtual Vec3 randomlyModifyPosition(const BlockPos&) const;
    virtual void addAABBs(const Block&, BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&) const;
    virtual const AABB& getAABB(BlockSource&, const BlockPos&, const Block&, AABB&, bool) const;
    virtual bool addCollisionShapes(const Block&, BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&, Actor*) const;
    virtual const AABB& getOutline(BlockSource&, const BlockPos&, AABB&) const;
    virtual bool getLiquidClipVolume(BlockSource&, const BlockPos&, AABB&) const;
    virtual void onProjectileHit(BlockSource&, const BlockPos&, const Actor&) const;
    virtual bool liquidCanFlowIntoFromDirection(FacingID, const GetBlockFunction&, const BlockPos&) const;
    virtual Brightness getLightEmission(const Block&) const;
    virtual bool shouldRandomTick() const;
    virtual bool hasVariableLighting() const;
    virtual bool isStrippable(const Block&) const;
    virtual const Block& getStrippedBlock(const Block&) const;
    virtual bool canProvideSupport(const Block&, FacingID, BlockSupportType) const;
    virtual bool canConnect(const Block&, FacingID, const Block&) const;
    virtual void getConnectedDirections(const Block&, const BlockPos&, BlockSource&, bool&, bool&, bool&, bool&) const;
    virtual bool isCropBlock() const;
    virtual bool isStemBlock() const;
    virtual bool isContainerBlock() const;
    virtual bool isCraftingBlock() const;
    virtual bool isInteractiveBlock() const;
    virtual bool isWaterBlocking() const;
    virtual bool isHurtableBlock() const;
    virtual bool isFenceBlock() const;
    virtual bool isFenceGateBlock() const;
    virtual bool isThinFenceBlock() const;
    virtual bool isWallBlock() const;
    virtual bool isStairBlock() const;
    virtual bool isSlabBlock() const;
    virtual bool isDoorBlock() const;
    virtual bool isRailBlock() const;
    virtual bool isButtonBlock() const;
    virtual bool canHurtAndBreakItem() const;
    virtual bool isSignalSource() const;
    virtual bool canBeOriginalSurface() const;
    virtual bool isValidAuxValue(int) const;
    virtual bool canFillAtPos(BlockSource&, const BlockPos&, const Block&) const;
    virtual const Block& sanitizeFillBlock(BlockSource&, const BlockPos&, const Block&) const;
    virtual void onFillBlock(BlockSource&, const BlockPos&, const Block&) const;
    virtual int getDirectSignal(BlockSource&, const BlockPos&, int) const;
    virtual bool waterSpreadCausesSpawn() const;
    virtual bool canContainLiquid() const;
    virtual bool shouldConnectToRedstone(BlockSource&, const BlockPos&, int) const;
    virtual void handleRain(BlockSource&, const BlockPos&, float) const;
    virtual bool canBeUsedInCommands(bool, const BaseGameVersion&) const;
    virtual float getThickness() const;
    virtual float getFlexibility(BlockSource&, const BlockPos&) const;
    virtual bool checkIsPathable(Actor&, const BlockPos&, const BlockPos&) const;
    virtual bool shouldDispense(BlockSource&, Container&) const;
    virtual bool dispense(BlockSource&, Container&, int, const Vec3&, FacingID) const;
    virtual void onPlace(BlockSource&, const BlockPos&) const;
    virtual void onRemove(BlockSource&, const BlockPos&) const;
    virtual void onExploded(BlockSource&, const BlockPos&, Actor*) const;
    virtual void onStepOn(Actor&, const BlockPos&) const;
    virtual void onFallOn(BlockSource&, const BlockPos&, Actor*, float) const;
    virtual void transformOnFall(BlockSource&, const BlockPos&, Actor*, float) const;
    virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
    virtual void onMove(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual bool detachesOnPistonMove(BlockSource&, const BlockPos&) const;
    virtual void movedByPiston(BlockSource&, const BlockPos&) const;
    virtual void setupRedstoneComponent(BlockSource&, const BlockPos&) const;
    virtual BlockProperty getRedstoneProperty(BlockSource&, const BlockPos&) const;
    virtual void updateEntityAfterFallOn(Actor&) const;
    virtual bool isBounceBlock() const;
    virtual bool ignoreEntitiesOnPistonMove(const Block&) const;
    virtual bool onFertilized(BlockSource&, const BlockPos&, Actor*, FertilizerType) const;
    virtual bool mayConsumeFertilizer(BlockSource&) const;
    virtual bool mayPick() const;
    virtual bool mayPick(BlockSource&, const Block&, bool) const;
    virtual bool mayPlace(BlockSource&, const BlockPos&, FacingID) const;
    virtual bool mayPlace(BlockSource&, const BlockPos&) const;
    virtual bool mayPlaceOn(BlockSource&, const BlockPos&) const;
    virtual bool tryToPlace(BlockSource&, const BlockPos&, const Block&, const ActorBlockSyncMessage*) const;
    virtual bool breaksFallingBlocks(const Block&) const;
    virtual void destroy(BlockSource&, const BlockPos&, const Block&, Actor*) const;
    virtual bool playerWillDestroy(Player&, const BlockPos&, const Block&) const;
    virtual bool getIgnoresDestroyPermissions(Actor&, const BlockPos&) const;
    virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
    virtual bool getSecondPart(BlockSource&, const BlockPos&, BlockPos&) const;
    virtual int getResourceCount(Random&, const Block&, int) const;
    virtual ItemInstance getResourceItem(Random&, const Block&, int) const;
    virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
    virtual void spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
    virtual bool spawnBurnResources(BlockSource&, float, float, float) const;
    virtual float getExplosionResistance(Actor*) const;
    virtual HitResult clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool) const;
    virtual bool use(Player&, const BlockPos&) const;
    virtual const Block& getPlacementBlock(Actor&, const BlockPos&, FacingID, const Vec3&, int) const;
    virtual int calcVariant(BlockSource&, const BlockPos&) const;
    virtual bool isAttachedTo(BlockSource&, const BlockPos&, BlockPos&) const;
    virtual bool attack(Player*, const BlockPos&) const;
    virtual void handleEntityInside(BlockSource&, const BlockPos&, Actor*, Vec3&) const;
    virtual void entityInside(BlockSource&, const BlockPos&, Actor&) const;
    virtual void playerDestroy(Player&, const BlockPos&, const Block&) const;
    virtual bool canSurvive(BlockSource&, const BlockPos&) const;
    virtual int getExperienceDrop(Random&) const;
    virtual bool canBeBuiltOver(BlockSource&, const BlockPos&) const;
    virtual void triggerEvent(BlockSource&, const BlockPos&, int, int) const;
    virtual void executeEvent(BlockSource&, const BlockPos&, const Block&, const std::string&, Actor&) const;
    virtual bool hasTag(BlockSource&, const BlockPos&, const Block&, const std::string&) const;
    virtual const MobSpawnerData* getMobToSpawn(const SpawnConditions&, BlockSource&) const;
    virtual Color getMapColor(BlockSource&, const BlockPos&) const;
    virtual Color getMapColor() const;
    virtual bool shouldStopFalling(Actor&) const;
    virtual bool pushesUpFallingBlocks() const;
    virtual float calcGroundFriction(Mob&, const BlockPos&) const;
    virtual bool canHaveExtraData() const;
    virtual bool hasComparatorSignal() const;
    virtual int getComparatorSignal(BlockSource&, const BlockPos&, const Block&, FacingID) const;
    virtual bool canSlide(BlockSource&, const BlockPos&) const;
    virtual int getIconYOffset() const;
    virtual BlockRenderLayer getRenderLayer() const;
    virtual BlockRenderLayer getRenderLayer(const Block&, BlockSource&, const BlockPos&) const;
    virtual std::string buildDescriptionId(const Block&) const;
    virtual bool isAuxValueRelevantForPicking() const;
    virtual int getColor(const Block&) const;
    virtual int getColor(BlockSource&, const BlockPos&, const Block&) const;
    virtual int getColorAtPos(BlockSource&, const BlockPos&) const;
    virtual int getColorForParticle(BlockSource&, const BlockPos&, const Block&) const;
    virtual bool isSeasonTinted(const Block&, BlockSource&, const BlockPos&) const;
    virtual void onGraphicsModeChanged(bool, bool, bool);
    virtual int getExtraRenderLayers() const;
    virtual float getShadeBrightness() const;
    virtual const AABB& getVisualShapeInWorld(const Block&, BlockSource&, const BlockPos&, AABB&, bool) const;
    virtual const AABB& getVisualShape(const Block&, AABB&, bool) const;
    virtual const AABB& getUIShape(const Block&, AABB&) const;
    virtual int telemetryVariant(BlockSource&, const BlockPos&) const;
    virtual int getVariant(const Block&) const;
    virtual bool canSpawnOn() const;
    virtual FacingID getMappedFace(FacingID, const Block&) const;
    virtual Flip getFaceFlip(FacingID, const Block&) const;
    virtual void animateTick(BlockSource&, const BlockPos&, Random&) const;
    virtual BlockLegacy& init();
    virtual BlockLegacy& setLightBlock(Brightness);
    virtual BlockLegacy& setLightEmission(float);
    virtual BlockLegacy& setExplodeable(float);
    virtual BlockLegacy& setDestroyTime(float);
    virtual BlockLegacy& setFriction(float);
    virtual BlockLegacy& addProperty(BlockProperty);
    virtual BlockLegacy& addState(const ItemState&);
    virtual BlockLegacy& addState(const ItemState&, size_t);
    virtual BlockLegacy& setAllowsRunes(bool);
    virtual BlockLegacy& setMapColor(const Color&);
    virtual bool canBeSilkTouched() const;
    virtual ItemInstance getSilkTouchItemInstance(const Block&) const;
    virtual void setVisualShape(const AABB&);
    virtual void setVisualShape(const Vec3&, const Vec3&);
    virtual const Block* tryLegacyUpgrade(DataID) const;
    virtual bool dealsContactDamage(const Actor&, const Block&, bool) const;

    const Block* tryGetStateFromLegacyData(DataID) const;
    Block& getDefaultState() const;
    short getBlockItemId() const;
    ItemActor* popResource(BlockSource&, const BlockPos&, const ItemInstance&) const;
    WeakPtr<BlockLegacy> createWeakPtr() {
        return BlockTypeRegistry::lookupByName(getRawNameId());
    }
    const std::string& getDescriptionId() const {
        return mDescriptionId;
    }
    const std::string& getRawNameId() const {
        return mRawNameId;
    }
    BlockLegacy& setCategory(CreativeItemCategory category) {
        mCreativeCategory = category;
        return *this;
    }
    bool operator==(const BlockLegacy& rhs) const {
        return this == &rhs;
    }
    bool operator!=(const BlockLegacy& rhs) const {
        return !(*this == rhs);
    }
};