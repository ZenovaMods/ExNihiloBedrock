#pragma once

#include "Zenova/Common.h"

#include "ActorType.h"
#include "ActorCategory.h"

class Actor;

class ActorClassTree {
public:
	static ActorType getEntityTypeIdLegacy(ActorType entityId) {
		return (ActorType)(Zenova::enum_cast(entityId) & Zenova::enum_cast(ActorType::TypeMask));
	}
    static bool isInstanceOf(const Actor&, const ActorType);
};