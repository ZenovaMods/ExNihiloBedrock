#pragma once

class VanillaItems {
public:
	static void registerItems(bool);
	static void initCreativeItemsCallback(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	static void initClientData();
};