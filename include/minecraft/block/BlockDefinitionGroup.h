#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class BlockDefinition {};

class BlockDefinitionGroup {
    std::unordered_map<std::string, std::unique_ptr<BlockDefinition>> mBlockDefinitions;
    int mLastBlockId;

public:
    void registerBlocks();
    int getNextBlockId() {
        return mLastBlockId++;
    }
};