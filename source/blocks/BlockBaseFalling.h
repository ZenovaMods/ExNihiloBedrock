#pragma once

#include "minecraft/HeavyBlock.h"

class BlockBaseFalling : public HeavyBlock {
public:
	BlockBaseFalling(const std::string&, int);
	virtual Color getDustColor(const Block&) const;
	virtual std::string getDustParticleName(const Block&) const;
};