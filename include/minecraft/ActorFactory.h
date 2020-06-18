#pragma once

#include <array>
#include <string>
#include <unordered_map>
#include <set>

#include "ActorType.h"
#include "ActorDefinitionIdentifier.h"
#include "Actor.h"

class ActorDefinitionGroup {};

using ActorFactoryFunction = std::unique_ptr<Actor>(*)(ActorDefinitionGroup*, const ActorDefinitionIdentifier*);

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

class ActorClassTree {
public:
	static ActorType getEntityTypeIdLegacy(ActorType entityId) {
		return (ActorType)((int)entityId & (int)ActorType::TypeMask);
	}
};

static std::set<std::string> _experimentalEntities;
extern std::unordered_map<std::string, ActorFactoryData>* _factoryFunctions;
static std::array<VanillaActorData, 99> _builtInEntityMappings;

class ActorFactory {
	Level& mLevel;

public:
	void setDefinitionGroup(ActorDefinitionGroup* group);
	void setDefinitionGroup2(ActorDefinitionGroup* group) {
		ActorInfoRegistry* infoRegistry = mLevel.getActorInfoRegistry();

		for (auto& entity : _builtInEntityMappings) {
			ActorFactoryData actorFactoryData;
			actorFactoryData.mIdentifier = ActorDefinitionIdentifier(entity.mActorType);
			actorFactoryData.mBaseIdentifier = ActorDefinitionIdentifier();
			actorFactoryData.mAllowSummon = entity.mAllowSummon;
			actorFactoryData.mFactory = entity.mFactory;
			actorFactoryData.mIsExperimental = entity.mIsExperimental;
			actorFactoryData.mActorType = entity.mActorType;
			(*_factoryFunctions)[actorFactoryData.mIdentifier.getCanonicalName()] = actorFactoryData;

			if (infoRegistry) {
				infoRegistry->registerActorInfo({ static_cast<unsigned int>(ActorClassTree::getEntityTypeIdLegacy(entity.mActorType)), actorFactoryData.mIdentifier, actorFactoryData.mBaseIdentifier, false, actorFactoryData.mAllowSummon, actorFactoryData.mIsExperimental });
			}

			if (actorFactoryData.mActorType != ActorType::Mob) {
				(*_factoryFunctions)[actorFactoryData.mIdentifier.getIdentifier()] = actorFactoryData;
			}

			if (entity.mIsExperimental) {
				_experimentalEntities.emplace(EntityTypeToString(entity.mActorType, ActorTypeNamespaceRules::ReturnWithoutNamespace));
			}
		}
	}
};