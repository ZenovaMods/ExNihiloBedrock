#include "BlockBaseFalling.h"

#include "ENBlocks.h"

BlockBaseFalling::BlockBaseFalling(const std::string& name, int id) : BlockLegacy(name, id, Material::getMaterial(MaterialType::Sand)) {

}
//
//Color BlockBaseFalling::getDustColor(const Block& block) const {
//	return Color(1.0F, 0.0F, 0.0F, 1.0F);
//}
//
//std::string BlockBaseFalling::getDustParticleName(const Block& block) const {
//	return "minecraft:falling_dust_sand_particle";
//}