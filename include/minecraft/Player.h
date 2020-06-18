#pragma once

#include "Mob.h"

class BlockActor;
class ChalkboardBlockActor;
class ChunkPos;
class ChunkSource;
class ComplexInventoryTransaction;
class Container;
class EventPacket;
class FrameUpdateContextBase;
class IContainerManager;
class IMinecraftEventing;
class InventoryTransaction;
class Item;
class MoveInputHandler;
class PlayerEventCoordinator;
class TextObjectRoot;
class Tick;

enum class BedSleepingResult : int;
enum class ClientPlayMode : int;
enum class CooldownType : int;
enum class GameType : int;
enum class MovementEventType : unsigned char;
enum class StructureFeatureType : signed char;

namespace Social { typedef unsigned int LocalUserId; }

class Player : public Mob {
public:
    virtual ~Player();
    virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList&);
    virtual void reloadHardcoded(Actor::InitializationMethod, const VariantParameterList&);
    virtual void prepareRegion(ChunkSource&);
    virtual void destroyRegion();
    virtual void suspendRegion();
    virtual void _fireWillChangeDimension();
    virtual void _fireDimensionChanged();
    virtual void changeDimensionWithCredits(DimensionType);
    virtual int tickWorld(const Tick&);
    virtual void frameUpdate(FrameUpdateContextBase&);
    virtual const std::vector<ChunkPos>& getTickingOffsets() const;
    virtual void normalTick();
    virtual void moveView();
    virtual void moveSpawnView(const Vec3&);
    virtual void setName(const std::string&);
    virtual void onSynchedDataUpdate(int);
    virtual void aiStep();
    virtual void move(const Vec3&);
    virtual void travel(float, float, float);
    virtual void checkMovementStats(const Vec3&);
    virtual StructureFeatureType getCurrentStructureFeature() const;
    virtual void jumpFromGround();
    virtual bool isAutoJumpEnabled() const;
    virtual void rideTick();
    virtual void die(const ActorDamageSource&);
    virtual void remove();
    virtual void respawn();
    virtual void dropEquipment(const ActorDamageSource&, int);
    virtual void dropEquipment();
    virtual bool drop(const ItemStack&, bool);
    virtual void resetRot();
    virtual void resetPos(bool);
    virtual bool isShootable();
    virtual bool isCreativeModeAllowed();
    virtual bool isInTrialMode();
    virtual void setSpeed(float);
    virtual bool hasResource(int);
    virtual void completeUsingItem();
    virtual int getItemUseDuration();
    virtual float getItemUseStartupProgress();
    virtual float getItemUseIntervalProgress();
    virtual bool isBlocking() const;
    virtual bool isDamageBlocked(const ActorDamageSource&) const;
    virtual void awardKillScore(Actor&, int);
    virtual void handleEntityEvent(ActorEvent, int);
    virtual std::vector<ItemStack const*> getAllHand() const;
    virtual std::vector<ItemStack const*> getAllEquipment() const;
    virtual bool add(ItemStack&);
    virtual CommandPermissionLevel getCommandPermissionLevel() const;
    virtual void setPermissions(CommandPermissionLevel);
    virtual void adjustDamageAmount(int&) const;
    virtual bool attack(Actor&);
    virtual const ItemStack& getCarriedItem() const;
    virtual void setCarriedItem(const ItemStack&);
    virtual void startCrafting(const BlockPos&, bool);
    virtual void startStonecutting(const BlockPos&);
    virtual void startDestroying();
    virtual void stopDestroying();
    virtual void openContainer(const BlockPos&);
    virtual void openContainer(const ActorUniqueID&);
    virtual void openFurnace(const BlockPos&);
    virtual void openBlastFurnace(const BlockPos&);
    virtual void openSmoker(const BlockPos&);
    virtual void openEnchanter(const BlockPos&);
    virtual void openAnvil(const BlockPos&);
    virtual void openGrindstone(const BlockPos&);
    virtual void openBrewingStand(const BlockPos&);
    virtual void openHopper(const BlockPos&);
    virtual void openHopper(const ActorUniqueID&);
    virtual void openDispenser(const BlockPos&, bool);
    virtual void openBeacon(const BlockPos&);
    virtual void openPortfolio();
    virtual void openBook(int, bool, int, BlockActor*);
    virtual void openCommandBlock(const BlockPos&);
    virtual void openCommandBlockMinecart(const ActorUniqueID&);
    virtual void openHorseInventory(const ActorUniqueID&);
    virtual void openTrading(const ActorUniqueID&, bool);
    virtual bool canOpenContainerScreen();
    virtual void openChalkboard(ChalkboardBlockActor&, bool);
    virtual void openNpcInteractScreen(Actor&);
    virtual void openInventory();
    virtual void openStructureEditor(const BlockPos&);
    virtual void openLabTable(const BlockPos&);
    virtual void openElementConstructor(const BlockPos&);
    virtual void openCompoundCreator(const BlockPos&);
    virtual void openMaterialReducer(const BlockPos&);
    virtual void openLoom(const BlockPos&);
    virtual void openStonecutter(const BlockPos&);
    virtual void openCartographyTable(const BlockPos&);
    virtual void displayChatMessage(const std::string&, const std::string&);
    virtual void displayClientMessage(const std::string&);
    virtual void displayLocalizableMessage(const std::string&, const std::vector<std::string>&);
    virtual void displayTextObjectMessage(const TextObjectRoot&, const std::string&, const std::string&);
    virtual void displayWhisperMessage(const std::string&, const std::string&, const std::string&, const std::string&);
    virtual float getCameraOffset() const;
    virtual float getRidingHeight();
    virtual ActorType getEntityTypeId() const;
    virtual bool isSleeping() const;
    virtual void setSleeping(bool);
    virtual BedSleepingResult startSleepInBed(const BlockPos&);
    virtual void stopSleepInBed(bool, bool);
    virtual bool canStartSleepInBed();
    virtual int getSleepTimer() const;
    virtual int getPreviousTickSleepTimer() const;
    virtual void sendInventory(bool);
    virtual void openSign(const BlockPos&);
    virtual void playEmote(const std::string&, bool);
    virtual bool isLocalPlayer() const;
    virtual bool isHostingPlayer() const;
    virtual bool useNewAi() const;
    virtual void useItem(ItemStack&, ItemUseMethod, bool);
    virtual bool isLoading() const;
    virtual bool isPlayerInitialized() const;
    virtual void stopLoading();
    virtual void registerTrackedBoss(ActorUniqueID);
    virtual void unRegisterTrackedBoss(ActorUniqueID);
    virtual bool isCreative() const;
    virtual bool isAdventure() const;
    virtual float getSpeed() const;
    virtual int getPortalCooldown() const;
    virtual int getPortalWaitTime() const;
    virtual void setPlayerGameType(GameType);
    virtual void _crit(Actor&);
    virtual bool isImmobile() const;
    virtual void sendMotionPacketIfNeeded();
    virtual IMinecraftEventing* getEventing() const;
    virtual Social::LocalUserId getUserId() const;
    virtual void sendEventPacket(EventPacket&) const;
    virtual void addExperience(int);
    virtual void addLevels(int);
    virtual void setArmor(ArmorSlot, const ItemStack&);
    virtual void setOffhandSlot(const ItemStack&);
    virtual std::unique_ptr<Packet> getAddPacket();
    virtual bool isWorldBuilder();
    virtual bool isInvulnerableTo(const ActorDamageSource&) const;
    virtual void setContainerData(IContainerManager&, int, int);
    virtual void slotChanged(IContainerManager&, int, const ItemStack&, const ItemStack&, bool);
    virtual void inventoryChanged(Container&, int, const ItemStack&, const ItemStack&);
    virtual void refreshContainer(IContainerManager&);
    virtual void deleteContainerManager();
    virtual const ItemStack& getEquippedTotem() const;
    virtual bool consumeTotem();
    virtual void setFieldOfViewModifier(float);
    virtual bool isPositionRelevant(DimensionType, const BlockPos&);
    virtual bool isEntityRelevant(const Actor&);
    virtual float getMapDecorationRotation() const;
    virtual void actuallyHurt(int, const ActorDamageSource*, bool);
    virtual void teleportTo(const Vec3&, bool, int, int);
    virtual void startSwimming();
    virtual void stopSwimming();
    virtual void startSpinAttack();
    virtual void stopSpinAttack();
    virtual bool isTeacher() const;
    virtual void onSuspension();
    virtual void onLinkedSlotsChanged();
    virtual bool canBePulledIntoVehicle() const;
    virtual void feed(int);
    virtual void startCooldown(const Item*);
    virtual int getItemCooldownLeft(CooldownType) const;
    virtual bool isItemInCooldown(CooldownType) const;
    virtual void sendInventoryTransaction(const InventoryTransaction&) const;
    virtual void sendComplexInventoryTransaction(std::unique_ptr<ComplexInventoryTransaction>) const;
    virtual void sendNetworkPacket(Packet&) const;
    virtual void updateGliding();
    virtual bool canExistWhenDisallowMob() const;
    virtual std::string getFormattedNameTag() const;
    virtual bool getAlwaysShowNameTag() const;
    virtual bool canAddRider(Actor&) const;
    virtual bool isJumping() const;
    virtual Vec3 getAttachPos(ActorLocation, float) const;
    virtual PlayerEventCoordinator& getPlayerEventCoordinator();
    virtual MoveInputHandler* getMoveInputHandler();
    virtual InputMode getInputMode() const;
    virtual ClientPlayMode getPlayMode() const;
    virtual void reportMovementTelemetry(const MovementEventType);
protected:
    virtual void updateAi();
    virtual bool _hurt(const ActorDamageSource&, int, bool, bool);
    virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
    virtual void addAdditionalSaveData(CompoundTag&);
    virtual void onMovePlayerPacketNormal(const Vec3&, const Vec2&, float);
    virtual void onBounceStarted(const BlockPos&, const Block&);
private:
    virtual void _onSizeUpdated();
public:
    virtual AnimationComponent& getAnimationComponent();
    virtual const HashedString& getActorRendererId() const;
private:
    virtual std::unique_ptr<BodyControl> initBodyControl();

public:
    const ItemStack& getSelectedItem() const;
    void causeFoodExhaustion(float);
};