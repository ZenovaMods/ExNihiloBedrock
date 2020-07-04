#pragma once

#include "ActorType.h"
#include "ActorCategory.h"

class Actor;

class ActorClassTree {
public:
	static ActorType getEntityTypeIdLegacy(ActorType entityId) {
		return (ActorType)((int)entityId & (int)ActorType::TypeMask);
	}
    static bool isInstanceOf(const Actor&, const ActorType);
};