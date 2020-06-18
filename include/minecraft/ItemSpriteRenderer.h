#pragma once

#include "ActorRenderer.h"

class Item;

class ItemSpriteRenderer : public ActorRenderer {
public:
	char filler[0x1B8];

	ItemSpriteRenderer(mce::TextureGroup&, Item*, bool);
	virtual ~ItemSpriteRenderer();
};