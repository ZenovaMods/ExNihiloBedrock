#pragma once

class ActorInfoRegistry;
class BlockDefinitionGroup;

class VanillaItems {
public:
	static WeakPtr<Item>& mBucket;
	static WeakPtr<Item>& mIronIngot;
	static WeakPtr<Item>& mGoldIngot;
	static WeakPtr<Item>& mShears;
	static WeakPtr<Item>& mString;

	static void registerItems(bool);
	static void initCreativeItemsCallback(ActorInfoRegistry*, BlockDefinitionGroup*, bool);
	static void initCreativeCategories();
	static void initClientData();
};