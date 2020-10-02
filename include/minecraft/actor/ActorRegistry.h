#pragma once

#include "ActorFactory.h"

typedef std::unordered_map<std::string, ActorFactoryData> ActorDataMap;

namespace VanillaActors {
	extern void registerVanillaActorData();
}

ActorDataMap& GetActorDataRegistry();

template<typename T>
__declspec(noinline)
std::unique_ptr<Actor> _actorFromClass(ActorDefinitionGroup* definitions, const ActorDefinitionIdentifier& definitionName) {
	return std::make_unique<T>(definitions, definitionName);
}

template<typename T, ActorType Type>
void _registerActorData(const std::string& fullName, bool allowSummon, bool experimental, float walkAnimSpeed = 0.0f) {
    ActorFactoryData afd;
    afd.mIdentifier = ActorDefinitionIdentifier(fullName);
    afd.mBaseIdentifier = ActorDefinitionIdentifier();
    afd.mAllowSummon = allowSummon;
    afd.mFactory = _actorFromClass<T>;
    afd.mIsExperimental = experimental;
    afd.mActorType = Type;
    afd.mWalkAnimSpeed = walkAnimSpeed;
    GetActorDataRegistry()[fullName] = afd;
}