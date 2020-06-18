#pragma once

#include <unordered_map>

class Actor;
class BlockSource;
class ItemActor;
class ItemStack;
class Level;
class Mob;
class StringKey;
class Vec3;
struct ActorDefinitionIdentifier;

class Spawner {
private:
    Level& mLevel;
    int mBaseTypeCount[2][7];
    std::unordered_map<StringKey, int> mEntityTypeCount[2];
    int mTotalEntityCount;

public:
    Mob* spawnMob(BlockSource&, const ActorDefinitionIdentifier&, Actor*, const Vec3&, bool, bool, bool);
    ItemActor* spawnItem(BlockSource&, const ItemStack&, Actor*, const Vec3&, int);
    Actor* spawnProjectile(BlockSource&, const ActorDefinitionIdentifier&, Actor*, const Vec3&, const Vec3&);
};