#pragma once

#include <limits>
#include <string>
#include <vector>

#include "Zenova/Common.h"

#include "../world/Level.h"
#include "SynchedActorData.h"
#include "ActorDefinitionIdentifier.h"
#include "ActorUniqueID.h"
#include "Attributes.h"

class AABB;
class ActorDamageSource;
class ActorDefinitionGroup;
class ActorInteraction;
class AnimationComponent;
class Block;
class BlockPos;
class BlockSource;
class ChangeDimensionPacket;
class CompoundTag;
class DataLoadHelper;
class Dimension;
class EquipmentTableDescription;
class HashedString;
class ItemActor;
class ItemStack;
class LootTable;
class MobEffectInstance;
class Packet;
class Player;
class RenderParams;
class Options;
class UIProfanityContext;
class VariantParameterList;
class Vec2;
class Vec3;

namespace Util { class HashString; }

enum class ActorEvent : unsigned char;
enum class ActorType : int;
enum class ArmorMaterialType : int;
enum class ArmorSlot : int;
enum class ArmorTextureType : int;
enum class CommandPermissionLevel : unsigned char;
enum class InputMode : unsigned int;
enum class ItemUseMethod : int;
enum class LevelSoundEvent : unsigned int;
enum class MaterialType : unsigned int;

typedef uint64_t HashType64;
typedef int DimensionType;
typedef unsigned char FacingID;

struct ActorLink {
    typedef std::vector<ActorLink> List;
};

enum class ActorLocation : int {
    Feet,
    Body,
    WeaponAttachPoint,
    Head,
    DropAttachPoint,
    ExplosionPoint,
    Eyes,
    BreathingPoint,
    Mouth
};

enum class ActorFlags : int {
    Unknown = -1,
    ONFIRE,
    SNEAKING,
    RIDING,
    SPRINTING,
    USINGITEM,
    INVISIBLE,
    TEMPTED,
    INLOVE,
    SADDLED,
    POWERED,
    IGNITED,
    BABY,
    CONVERTING,
    CRITICAL,
    CAN_SHOW_NAME,
    ALWAYS_SHOW_NAME,
    NOAI,
    SILENT,
    WALLCLIMBING,
    CANCLIMB,
    CANSWIM,
    CANFLY,
    CANWALK,
    RESTING,
    SITTING,
    ANGRY,
    INTERESTED,
    CHARGED,
    TAMED,
    ORPHANED,
    LEASHED,
    SHEARED,
    GLIDING,
    ELDER,
    MOVING,
    BREATHING,
    CHESTED,
    STACKABLE,
    SHOW_BOTTOM,
    STANDING,
    SHAKING,
    IDLING,
    CASTING,
    CHARGING,
    WASD_CONTROLLED,
    CAN_POWER_JUMP,
    LINGERING,
    HAS_COLLISION,
    HAS_GRAVITY,
    FIRE_IMMUNE,
    DANCING,
    ENCHANTED,
    RETURNTRIDENT,
    CONTAINER_IS_PRIVATE,
    IS_TRANSFORMING,
    DAMAGENEARBYMOBS,
    SWIMMING,
    BRIBED,
    IS_PREGNANT,
    LAYING_EGG,
    RIDER_CAN_PICK,
    TRANSITION_SITTING,
    EATING,
    LAYING_DOWN,
    SNEEZING,
    TRUSTING,
    ROLLING,
    SCARED,
    IN_SCAFFOLDING,
    OVER_SCAFFOLDING,
    FALL_THROUGH_SCAFFOLDING,
    BLOCKING,
    TRANSITION_BLOCKING,
    BLOCKED_USING_SHIELD,
    BLOCKED_USING_DAMAGED_SHIELD,
    SLEEPING,
    WANTS_TO_WAKE,
    TRADE_INTEREST,
    DOOR_BREAKER,
    BREAKING_OBSTRUCTION,
    DOOR_OPENER,
    IS_ILLAGER_CAPTAIN,
    STUNNED,
    ROARING,
    DELAYED_ATTACK,
    IS_AVOIDING_MOBS,
    FACING_TARGET_TO_RANGE_ATTACK,
    HIDDEN_WHEN_INVISIBLE,
    IS_IN_UI,
    STALKING,
    EMOTING,
    CELEBRATING,
    Count
};

class Actor {
public:
    enum class InitializationMethod : unsigned char;

public:
    char filler0[0x128];
    SynchedActorData mEntityData;
private:
    char filler1[0x1D0];
    BlockSource* mRegion;
    Dimension* mDimension;
    Level* mLevel;
    HashedString mActorRendererId;
protected:
    HashedString mActorRendererIdThatAnimationComponentWasInitializedWith;
    bool mChanged;
    bool mRemoved;
    bool mGlobal;
    bool mAutonomous;
    ActorType mActorType;
    ActorDefinitionIdentifier mActorIdentifier;
    char filler2[0x400];

public:
    virtual bool hasComponent(const Util::HashString&) const;
    virtual void reloadHardcoded(InitializationMethod, const VariantParameterList&);
    virtual void reloadHardcodedClient(InitializationMethod, const VariantParameterList&);
    virtual void initializeComponents(InitializationMethod, const VariantParameterList&);
    virtual void reloadComponents(InitializationMethod, const VariantParameterList&);

    virtual ~Actor();
    virtual void reset();
    virtual int getOnDeathExperience();
    virtual ActorType getOwnerEntityType();
    virtual void remove();
    virtual void setPos(const Vec3&);
    virtual const Vec3& getPos() const;
    virtual const Vec3& getPosOld() const;
    virtual const Vec3 getPosExtrapolated(float) const;
    virtual Vec3 getAttachPos(ActorLocation, float) const;
    virtual Vec3 getFiringPos() const;
    virtual void setRot(const Vec2&);
    virtual void move(const Vec3&);
    virtual Vec3 getInterpolatedRidingPosition(float) const;
    virtual float getInterpolatedBodyRot(float) const;
    virtual float getInterpolatedHeadRot(float) const;
    virtual float getInterpolatedBodyYaw(float) const;
    virtual float getYawSpeedInDegreesPerSecond() const;
    virtual float getInterpolatedWalkAnimSpeed(float) const;
    virtual Vec3 getInterpolatedRidingOffset(float) const;
    virtual void checkBlockCollisions(const AABB&);
    virtual void checkBlockCollisions();
    virtual bool breaksFallingBlocks() const;
    virtual void blockedByShield(const ActorDamageSource&, Actor&);
    virtual void moveRelative(float, float, float, float);
    virtual void teleportTo(const Vec3&, bool, int, int);
    virtual bool tryTeleportTo(const Vec3&, bool, bool, int, int);
    virtual void chorusFruitTeleport(Vec3&);
    virtual void lerpTo(const Vec3&, const Vec2&, int);
    virtual void lerpMotion(const Vec3&);
    virtual std::unique_ptr<Packet> getAddPacket();
    virtual void normalTick();
    virtual void baseTick();
    virtual void rideTick();
    virtual void positionRider(Actor&, float);
    virtual float getRidingHeight();
    virtual bool startRiding(Actor&);
    virtual void addRider(Actor&);
    virtual void flagRiderToRemove(Actor&);
    virtual std::string getExitTip(const std::string&, InputMode) const;
    virtual bool intersects(const Vec3&, const Vec3&) const;
    virtual bool isFree(const Vec3&, float);
    virtual bool isFree(const Vec3&);
    virtual bool isInWall() const;
    virtual bool isInvisible() const;
    virtual bool canShowNameTag() const;
    virtual bool canExistInPeaceful() const;
    virtual void setNameTagVisible(bool);
    virtual const std::string& getNameTag() const;
    virtual HashType64 getNameTagAsHash() const;
    virtual std::string getFormattedNameTag() const;
    virtual void filterFormattedNameTag(const UIProfanityContext&);
    virtual void setNameTag(const std::string&);
    virtual bool getAlwaysShowNameTag() const;
    virtual void setScoreTag(const std::string&);
    virtual const std::string& getScoreTag() const;
    virtual bool isInWater() const;
    virtual bool hasEnteredWater() const;
    virtual bool isImmersedInWater() const;
    virtual bool isInWaterOrRain() const;
    virtual bool isInLava() const;
    virtual bool isUnderLiquid(MaterialType) const;
    virtual bool isOverWater() const;
    virtual void makeStuckInBlock(float);
    virtual float getCameraOffset() const;
    virtual float getShadowHeightOffs();
    virtual float getShadowRadius() const;
    virtual Vec3 getHeadLookVector(float);
    virtual bool canSeeInvisible() const;
    virtual bool canSee(const Actor&) const;
    virtual bool canSee(const Vec3&) const;
    virtual bool isSkyLit(float);
    virtual float getBrightness(float) const;
    virtual bool interactPreventDefault();
    virtual void playerTouch(Player&);
    virtual void onAboveBubbleColumn(const bool);
    virtual void onInsideBubbleColumn(const bool);
    virtual bool isImmobile() const;
    virtual bool isSilent();
    virtual bool isPickable();
    virtual bool isFishable() const;
    virtual bool isSleeping() const;
    virtual bool isShootable();
    virtual bool isSneaking() const;
    virtual void setSneaking(bool);
    virtual bool isBlocking() const;
    virtual bool isDamageBlocked(const ActorDamageSource&) const;
    virtual bool isAlive() const;
    virtual bool isOnFire() const;
    virtual bool isOnHotBlock() const;
    virtual bool isCreativeModeAllowed();
    virtual bool isSurfaceMob() const;
    virtual bool isTargetable() const;
    virtual bool canAttack(Actor*, bool) const;
    virtual void setTarget(Actor*);
    virtual Actor* findAttackTarget();
    virtual bool isValidTarget(Actor*) const;
    virtual bool attack(Actor&);
    virtual void performRangedAttack(Actor&, float);
    virtual void adjustDamageAmount(int&) const;
    virtual int getEquipmentCount() const;
    virtual void setOwner(const ActorUniqueID);
    virtual void setSitting(bool);
    virtual void onTame();
    virtual void onFailedTame();
    virtual int getInventorySize() const;
    virtual int getEquipSlots() const;
    virtual int getChestSlots() const;
    virtual void setStanding(bool);
    virtual bool canPowerJump() const;
    virtual void setCanPowerJump(bool);
    virtual bool isJumping() const;
    virtual bool isEnchanted() const;
    virtual void rideJumped();
    virtual void rideLanded(const Vec3&, const Vec3&);
    virtual bool shouldRender() const;
    virtual bool isInvulnerableTo(const ActorDamageSource&) const;
    virtual void actuallyHurt(int, const ActorDamageSource*, bool);
    virtual void animateHurt();
    virtual bool doFireHurt(int);
    virtual void onLightningHit();
    virtual void onBounceStarted(const BlockPos&, const Block&);
    virtual void feed(int);
    virtual void handleEntityEvent(ActorEvent, int);
    virtual float getPickRadius();
    virtual const HashedString& getActorRendererId() const;
    virtual ItemActor* spawnAtLocation(int, int);
    virtual ItemActor* spawnAtLocation(int, int, float);
    virtual ItemActor* spawnAtLocation(const Block&, int);
    virtual ItemActor* spawnAtLocation(const Block&, int, float);
    virtual ItemActor* spawnAtLocation(const ItemStack&, float);
    virtual void despawn();
    virtual void killed(Actor&);
    virtual void awardKillScore(Actor&, int);
    virtual void setArmor(ArmorSlot, const ItemStack&);
    virtual const ItemStack& getArmor(ArmorSlot) const;
    virtual ArmorMaterialType getArmorMaterialTypeInSlot(ArmorSlot) const;
    virtual ArmorTextureType getArmorMaterialTextureTypeInSlot(ArmorSlot) const;
    virtual float getArmorColorInSlot(ArmorSlot, int) const;
    virtual void setEquippedSlot(ArmorSlot, int, int);
    virtual void setEquippedSlot(ArmorSlot, const ItemStack&);
    virtual const ItemStack& getCarriedItem() const;
    virtual void setCarriedItem(const ItemStack&);
    virtual void setOffhandSlot(const ItemStack&);
    virtual const ItemStack& getEquippedTotem() const;
    virtual bool consumeTotem();
    virtual bool save(CompoundTag&);
    virtual void saveWithoutId(CompoundTag&);
    virtual bool load(const CompoundTag&, DataLoadHelper&);
    virtual void loadLinks(const CompoundTag&, ActorLink::List&, DataLoadHelper&);
    virtual ActorType getEntityTypeId() const;
    virtual const HashedString& queryEntityRenderer() const;
    virtual ActorUniqueID getSourceUniqueID() const;
    virtual void setOnFire(int);
    virtual AABB getHandleWaterAABB() const;
    virtual void handleInsidePortal(const BlockPos&);
    virtual int getPortalCooldown() const;
    virtual int getPortalWaitTime() const;
    virtual DimensionType getDimensionId() const;
    virtual bool canChangeDimensions() const;
    virtual void changeDimension(DimensionType, bool);
    virtual void changeDimension(const ChangeDimensionPacket&);
    virtual ActorUniqueID getControllingPlayer() const;
    virtual void checkFallDamage(float, bool);
    virtual void causeFallDamage(float);
    virtual void handleFallDistanceOnServer(float, bool);
    virtual void playSynchronizedSound(LevelSoundEvent, const Vec3&, const Block&, bool);
    virtual void playSynchronizedSound(LevelSoundEvent, const Vec3&, int, bool);
    virtual void onSynchedDataUpdate(int);
    virtual bool canAddRider(Actor&) const;
    virtual bool canBePulledIntoVehicle() const;
    virtual bool inCaravan() const;
    virtual bool isLeashableType();
    virtual void tickLeash();
    virtual void sendMotionPacketIfNeeded();
    virtual bool canSynchronizeNewEntity() const;
    virtual void stopRiding(bool, bool, bool);
    virtual void startSwimming();
    virtual void stopSwimming();
    virtual void buildDebugInfo(std::string&) const;
    virtual CommandPermissionLevel getCommandPermissionLevel() const;
    virtual AttributeInstance* getMutableAttribute(const Attribute&);
    virtual const AttributeInstance& getAttribute(const Attribute&) const;
    virtual int getDeathTime() const;
    virtual void heal(int);
    virtual bool isInvertedHealAndHarm() const;
    virtual bool canBeAffected(int) const;
    virtual bool canBeAffected(const MobEffectInstance&) const;
    virtual bool canBeAffectedByArrow(const MobEffectInstance&) const;
    virtual void onEffectAdded(MobEffectInstance&);
    virtual void onEffectUpdated(const MobEffectInstance&);
    virtual void onEffectRemoved(MobEffectInstance&);
    virtual AnimationComponent& getAnimationComponent();
    virtual void openContainerComponent(Player&);
    virtual void swing();
    virtual void useItem(ItemStack&, ItemUseMethod, bool);
    virtual bool hasOutputSignal(FacingID) const;
    virtual int getOutputSignal() const;
    virtual void getDebugText(std::vector<std::string>&);
    virtual float getMapDecorationRotation() const;
    virtual float getRiderYRotation(const Actor&) const;
    virtual float getYHeadRot() const;
    virtual bool isWorldBuilder();
    virtual bool isCreative() const;
    virtual bool isAdventure() const;
    virtual bool add(ItemStack&);
    virtual bool drop(const ItemStack&, bool);
    virtual bool getInteraction(Player&, ActorInteraction&, const Vec3&);
    virtual bool canDestroyBlock(const Block&) const;
    virtual void setAuxValue(int auxValue) {}
    virtual void setSize(float, float);
    virtual int getLifeSpan() const;
    virtual void onOrphan();
    virtual void wobble();
    virtual bool wasHurt();
    virtual void startSpinAttack();
    virtual void stopSpinAttack();
    virtual void setDamageNearbyMobs(bool);
    virtual void renderDebugServerState(const Options&);
    virtual void reloadLootTable();
    virtual void reloadLootTable(const EquipmentTableDescription*);
    virtual float getDeletionDelayTimeSeconds() const;
    virtual void kill();
    virtual void die(const ActorDamageSource&);
    virtual bool shouldTick() const;
    virtual void updateEntitySpecificMolangVariables(RenderParams&);
    virtual bool canMakeStepSound() const;
    virtual void outOfWorld();
    virtual bool _hurt(const ActorDamageSource&, int, bool, bool);
    virtual void markHurt();
    virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void _playStepSound(const BlockPos&, const Block&);
    virtual void _playFlySound(const BlockPos&, const Block&);
    virtual bool _makeFlySound() const;
    virtual void checkInsideBlocks(float);
    virtual void pushOutOfBlocks(const Vec3&);
    virtual bool updateWaterState();
    virtual void doWaterSplashEffect();
    virtual void spawnTrailBubbles();
    virtual void updateInsideBlock();
    virtual LootTable* getLootTable();
    virtual LootTable* getDefaultLootTable();
    virtual void _removeRider(const ActorUniqueID&, bool, bool);
    virtual void _onSizeUpdated();
    virtual void _doAutoAttackOnTouch(Actor&);

public:
    int getVariant() const;
    void setVariant(int);
    void setPersistent();
    bool isPersistent() const;
    bool getStatusFlag(ActorFlags) const;
    bool setStatusFlag(ActorFlags, bool);
    void addEffect(const MobEffectInstance&);
    Random& getRandom() const {
        return mLevel->getRandom();
    }
    BlockSource& getRegion() const {
        return *mRegion;
    }
    const BlockSource& getRegionConst() const {
        return *mRegion;
    }
    Dimension& getDimension() const {
        return *mDimension;
    }
    const Dimension& getDimensionConst() const {
        return *mDimension;
    }
    Level* _getLevelPtr() const {
        return mLevel;
    }
    Level& getLevel() {
        return *mLevel;
    }
    const Level& getLevel() const {
        return *mLevel;
    }
    SynchedActorData& getEntityData() {
        return mEntityData;
    }
    int getHealth() const {
        return (int)getAttribute(SharedAttributes::HEALTH).getCurrentValue();
    }
    int getMaxHealth() const {
        return (int)getAttribute(SharedAttributes::HEALTH).getMaxValue();
    }
    void serializationSetHealth(int newHealth) {
        getMutableAttribute(SharedAttributes::HEALTH)->serializationSetValue((float)newHealth, Zenova::enum_cast(AttributeOperands::OPERAND_CURRENT), std::numeric_limits<float>::max());
    }
    bool isPowered() const {
        return getStatusFlag(ActorFlags::POWERED);
    }
    void setPowered(bool value) {
        setStatusFlag(ActorFlags::POWERED, value);
    }
    bool hasType(ActorType type) const {
        return getEntityTypeId() == type;
    }
};