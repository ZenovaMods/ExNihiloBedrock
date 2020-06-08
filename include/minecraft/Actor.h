#pragma once

class BlockSource;

class Actor {
private:
    char filler[0x310];
    BlockSource* mRegion;

public:
    virtual ~Actor();
    BlockSource& getRegion() const {
        return *mRegion;
    }
    const BlockSource& getRegionConst() const {
        return *mRegion;
    }
};