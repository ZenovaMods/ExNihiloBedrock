#pragma once

class BlockSource;

class Actor {
private:
    char filler[0x318];
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