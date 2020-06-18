#pragma once

#include <unordered_map>
#include <memory>

#include "ActorRenderer.h"
#include "StringHash.h"

class ActorResourceDefinitionGroup;
class BlockTessellator;
class GeometryGroup;
class SemVersion;

namespace mce { class TextureGroup; }

class ActorRenderDispatcher {
public:
	std::unordered_map<StringKey, std::unique_ptr<ActorRenderer>> mRendererMap;
	std::unordered_map<StringKey, std::unique_ptr<DataDrivenRenderer>> mDataDrivenMap;
	unsigned char mUchar;

	virtual ~ActorRenderDispatcher();
	void initializeEntityRenderers(GeometryGroup&, mce::TextureGroup&, BlockTessellator&, const ActorResourceDefinitionGroup&, const SemVersion&);
	ActorRenderer* getRenderer(const HashedString&) const;
	DataDrivenRenderer* getDataDrivenRenderer(const HashedString&) const;
};