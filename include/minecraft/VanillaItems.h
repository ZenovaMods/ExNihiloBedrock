#pragma once

class ActorInfoRegistry;
class BlockDefinitionGroup;

class VanillaItems {
public:
	static void registerItems(bool);
	static void initCreativeItemsCallback(ActorInfoRegistry*, BlockDefinitionGroup*, bool);
	static void initCreativeCategories();
	static void initClientData();
};