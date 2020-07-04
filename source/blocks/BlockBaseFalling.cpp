#include "BlockBaseFalling.h"

#include "ENBlocks.h"

BlockBaseFalling::BlockBaseFalling(const std::string& name, int id) : HeavyBlock(name, id, Material::getMaterial(MaterialType::Sand)) {
	setCategory(CreativeItemCategory::DECORATIONS);
	setDestroyTime(0.7F);
}

Color BlockBaseFalling::getDustColor(const Block& block) const {
	return Color::NIL;
}

std::string BlockBaseFalling::getDustParticleName(const Block& block) const {
	return "minecraft:falling_dust_gravel_particle";
}