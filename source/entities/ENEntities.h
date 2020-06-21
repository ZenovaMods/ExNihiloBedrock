#pragma once

class ActorRenderDispatcher;
namespace mce { class TextureGroup; }

class ENEntities {
public:
	static void initEntityMap();
	static void initEntityData();
	static void initProjectileMap();
	static void initRenderers(ActorRenderDispatcher*, mce::TextureGroup&);
};