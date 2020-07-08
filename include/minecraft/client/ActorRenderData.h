#pragma once

#include "../util/Vec3.h"

class Actor;

class ActorRenderData {
public:
	Actor& mActor;
	Vec3 mPos;
	float mFloat1;
	float mFloat2;

	Actor& getActor() { return mActor; }
	Vec3& getPos() { return mPos; }
};