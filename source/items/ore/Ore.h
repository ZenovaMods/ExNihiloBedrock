#pragma once

#include <string>
#include "minecraft/util/Color.h"

class ItemInfo;

class Ore {
private:
	std::string name;
	Color color;
	ItemInfo* result;

public:
	Ore(std::string name, Color color, ItemInfo* result) : name(name), color(color), result(result) {}
	std::string getName() { return name; }
	Color getColor() { return color; }
	ItemInfo* getResult() { return result; }
};