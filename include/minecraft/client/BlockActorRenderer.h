#pragma once

#include <string>
#include <vector>

#include "BaseActorRenderer.h"

class BaseActorRenderContext;
class BlockActor;
class BlockActorRenderData;
class NameTagRenderObject;
class Tessellator;
class Vec3;

class BlockActorRenderer : public BaseActorRenderer {
public:
	BlockActorRenderer() : BaseActorRenderer() {}

	virtual void render(BaseActorRenderContext&, BlockActorRenderData&) = 0;
	virtual void renderAlpha(BaseActorRenderContext&, BlockActorRenderData&) {}
	virtual std::vector<NameTagRenderObject> extractText(Tessellator&, BlockActor&, const std::string&, int, Vec3, bool);
};