#pragma once

#include <vector>
#include <string>

#include "SharedPtr.h"

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
	
	static std::vector<SharedPtr<Item>>* mItemRegistry;
};