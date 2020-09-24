#pragma once

#include <map>
#include <memory>

#include "../block/BlockActorRendererId.h"

class ActorResourceDefinitionGroup;
class BaseActorRenderContext;
class Block;
class BlockActor;
class BlockActorRenderer;
class BlockSource;
class BlockTessellator;
class GeometryGroup;
class Vec3;

namespace mce {
	class ClientTexture;
	class MaterialPtr;
	class TextureGroup;
}

class BlockActorRenderDispatcher {
public:
	std::map<BlockActorRendererId, std::unique_ptr<BlockActorRenderer>> mRendererMap;

	void initializeBlockEntityRenderers(GeometryGroup&, mce::TextureGroup&, BlockTessellator&, const ActorResourceDefinitionGroup&);
	void render(BaseActorRenderContext&, BlockSource&, BlockActor&, const Block&, const Vec3&, bool, const mce::MaterialPtr&, const mce::ClientTexture*, int);
};