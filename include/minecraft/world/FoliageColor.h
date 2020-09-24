#pragma once

#include <array>
#include <string>
#include <unordered_map>

class BlockSource;
class BlockPos;
class Random;

class FoliageColor {
public:
    static int getGrassColor(const std::string&, float, float);
    static int getGrassColor(const std::string&, float);
    static int getGrassColor(float, float);
    static int getGrassColor(BlockSource&, const BlockPos&);
    static int getFoliageColor(const std::string&, float, float);
    static int getFoliageColor(float, float);
    static int getMapGrassColor(float, float);
    static int getMapGrassColor(BlockSource&, const BlockPos&);
    static int getMapFoliageColor(float, float);
    static int getEvergreenColor(float, float);
    static int getBirchColor(float, float);
    static int getMapEvergreenColor(float, float) {
        return 0x619961;
    }
    static int getMapBirchColor(float, float) {
        return 0x80A755;
    }
    static int getDefaultColor();
    static void buildGrassColor(const BlockPos&, const BlockPos&, BlockSource&, Random&);
private:
    static int _index(float, float);
    static int _getX(float, float);
    static int _getY(float, float);
    static int _toRGB(int);
    static void calculateMapGrassColorHelper(BlockSource&, const BlockPos&, const BlockPos&, int&, int&, int&);
};