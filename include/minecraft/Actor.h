#pragma once

#include "Level.h"

class BlockSource;
class Dimension;

class Actor {
private:
    char filler[0x318];
    BlockSource* mRegion;
    Dimension* mDimension;
    Level* mLevel;

public:
    virtual ~Actor();
    Random& getRandom() const {
        return mLevel->getRandom();
    }
    BlockSource& getRegion() const {
        return *mRegion;
    }
    const BlockSource& getRegionConst() const {
        return *mRegion;
    }
    Dimension& getDimension() const {
        return *mDimension;
    }
    const Dimension& getDimensionConst() const {
        return *mDimension;
    }
    Level* _getLevelPtr() const {
        return mLevel;
    }
    Level& getLevel() {
        return *mLevel;
    }
    const Level& getLevel() const {
        return *mLevel;
    }
};

class Mob : public Actor {
public:
    virtual ~Mob();
};

class Player : public Mob {
public:
    virtual ~Player();
    const ItemStack& getSelectedItem() const;
    void causeFoodExhaustion(float);
};