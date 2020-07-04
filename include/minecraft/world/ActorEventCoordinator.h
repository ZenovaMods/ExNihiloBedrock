#pragma once

#include <string>

#include "../CommonTypes.h"

class Actor;
class ActorDamageSource;
class BlockPos;
class HitResult;
class ItemInstance;
class ItemStack;
class Vec3;

enum class ArmorSlot : int;
enum class HandSlot : int;
enum class ItemAcquisitionMethod : int;
enum class ItemUseMethod : int;

class ActorEventCoordinator {
public:
    void sendActorAttack(Actor&, Actor&);
    void sendActorHurt(Actor&, const ActorDamageSource&, int, int);
    void sendActorMove(Actor&, const Vec3&);
    void sendActorTick(Actor&);
    void sendActorSneakChanged(Actor&, bool);
    void sendActorStartRiding(Actor&, Actor&);
    void sendActorStopRiding(Actor&, bool, bool, bool);
    void sendActorDeath(Actor&, const ActorDamageSource&);
    void sendActorDefinitionEventTriggered(Actor&, const std::string&);
    void sendActorRemoved(Actor&);
    void sendActorCreated(Actor&);
    void sendActorCarriedItemChanged(Actor&, const ItemInstance&, const ItemInstance&, HandSlot);
    void sendActorEquippedArmor(Actor&, const ItemInstance&, ArmorSlot);
    void sendActorUseItem(Actor&, const ItemInstance&, ItemUseMethod);
    void sendActorUseItemOn(Actor&, const ItemStack&, const BlockPos&, FacingID);
    void sendActorAcquiredItem(Actor&, const ItemInstance&, uint32_t, ItemAcquisitionMethod, Actor*);
    void sendActorPlacedItem(Actor&, const ItemInstance&);
    void sendActorDroppedItem(Actor&, const ItemInstance&);
    void sendProjectileHit(Actor&, const HitResult&);
    void sendActorTeleported(Actor&);
};