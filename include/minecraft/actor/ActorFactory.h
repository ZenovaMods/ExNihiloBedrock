#pragma once

#include <array>
#include <string>
#include <unordered_map>
#include <set>

#include "ActorType.h"
#include "ActorClassTree.h"
#include "ActorDefinitionIdentifier.h"

class Level;
class Vec3;
class Vec2;
class ActorDefinitionGroup {};

using ActorFactoryFunction = std::unique_ptr<Actor>(*)(ActorDefinitionGroup*, const ActorDefinitionIdentifier&);

struct VanillaActorData {
	ActorType mActorType;
	bool mAllowSummon;
	ActorFactoryFunction mFactory;
	bool mIsExperimental;
};

struct ActorFactoryData {
	ActorDefinitionIdentifier mIdentifier;
	ActorDefinitionIdentifier mBaseIdentifier;
	bool mAllowSummon;
	ActorFactoryFunction mFactory;
	bool mIsExperimental;
	ActorType mActorType;
	float mWalkAnimSpeed;
};

struct ActorInfo {
	unsigned int mRuntimeId;
	ActorDefinitionIdentifier mIdentifier;
	ActorDefinitionIdentifier mBaseIdentifier;
	bool mHasSpawnEgg;
	bool mIsSummonable;
	bool mIsExperimental;
};

class ActorInfoRegistry {
public:
	void registerActorInfo(const ActorInfo&);
};

static std::set<std::string> _experimentalEntities;
extern std::unordered_map<std::string, ActorFactoryData>& _factoryFunctions;
static std::array<VanillaActorData, 99> _builtInEntityMappings;

class ActorFactory {
	Level& mLevel;

public:
	void setDefinitionGroup(ActorDefinitionGroup* group);
	std::unique_ptr<Actor> createSpawnedEntity(const ActorDefinitionIdentifier&, Actor*, const Vec3&, const Vec2&);
	std::unique_ptr<Actor> createTransformedEntity(const ActorDefinitionIdentifier&, Actor*);
};