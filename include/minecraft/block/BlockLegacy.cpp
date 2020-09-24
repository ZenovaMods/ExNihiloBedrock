#include "BlockLegacy.h"

#include "Block.h"

void BlockLegacy::addLegacyDataFromPermutations() {
    for (auto& block : mBlockPermutations) {
        addLegacyBlockData(block->getDataDEPRECATED(), block.get());
    }
}