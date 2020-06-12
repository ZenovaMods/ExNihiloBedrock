#pragma once

#include <vector>
#include <string>

#include "SharedPtr.h"
#include "Block.h"

class Item;

class ItemRegistry {
public:
	template<typename T, typename... Args>
	static WeakPtr<T> registerItem(const std::string& name, short id, Args&&... args) {
		return ItemRegistry::registerItemShared<T>(name, id + 256, std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	static WeakPtr<T> registerItemShared(Args&&... args) {
		SharedPtr<Item> itemReg = SharedPtr<T>::make(std::forward<Args>(args)...);
		ItemRegistry::registerItem(itemReg);
		return itemReg;
	}

	static void registerItem(SharedPtr<Item>);
	static void shutdown();
	

	static WeakPtr<Item> lookupByName(int&, int&, const std::string&);
	static WeakPtr<Item> lookupByName(int&, const std::string&);
	static WeakPtr<Item> lookupByName(const std::string& inString) {
		int itemAux;
		return lookupByName(itemAux, inString);
	}
	static WeakPtr<Item> getItem(const short);
	static WeakPtr<Item> getItem(const Block& block) {
		return getItem(block.getLegacyBlock());
	}
	static WeakPtr<Item> getItem(const BlockLegacy& blockLegacy) {
		return getItem(blockLegacy.getBlockItemId());
	}

	static std::vector<SharedPtr<Item>>* mItemRegistry;
};