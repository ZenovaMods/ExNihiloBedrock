#pragma once

#include "minecraft/HeavyBlock.h"

class BlockBaseFalling : public BlockLegacy {
public:
	BlockBaseFalling(const std::string&, int);
	/*virtual ~BlockBaseFalling() {}
	virtual Color getDustColor(const Block&) const;
	virtual std::string getDustParticleName(const Block&) const;*/
};