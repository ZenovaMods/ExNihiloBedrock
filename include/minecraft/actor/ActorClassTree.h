#pragma once

#include "ActorType.h"
#include "ActorCategory.h"

class Actor;

class ActorClassTree {
public:
	static ActorType getEntityTypeIdLegacy(ActorType entityId) {
		return (ActorType)(enum_cast(entityId) & enum_cast(ActorType::TypeMask));
	}
    static bool isInstanceOf(const Actor&, const ActorType);
};