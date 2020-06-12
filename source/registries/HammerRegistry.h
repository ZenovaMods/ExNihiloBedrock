#pragma once

#include <map>
#include <vector>
#include <string>

class BlockInfo;
class HammerReward;
class Block;
class ItemInstance;
class Random;

class HammerRegistry {
public:
	static std::map<BlockInfo*, std::vector<HammerReward*>> registry;

public:
	static void loadJson(const std::string&);
	static void saveJson(const std::string&);
	static void addHammerRecipe(BlockInfo*, ItemInstance*, int, float, float);
	static void registerRecipe(BlockInfo*, ItemInstance*, int, float, float);
	static std::vector<ItemInstance*> getRewardDrops(Random&, const Block*, int, int);
	static std::vector<HammerReward*> getRewards(const Block*);
	static bool registered(const Block*);
	static void registerDefaults();
	static std::vector<HammerReward*> getRewards(const Block*, int);
	static std::vector<HammerReward*> getRegistryValue(BlockInfo*);
};