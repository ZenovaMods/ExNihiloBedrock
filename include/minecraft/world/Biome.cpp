#include "Biome.h"

#include "FoliageColor.h"
#include "../util/Math.h"

int Biome::getBirchFoliageColor(const BlockPos& pos) const {
	float temp = mce::Math::clamp(getDefaultBiomeTemperature(), 0.0F, 1.0F);
	float down = mce::Math::clamp(getDownfall(), 0.0F, 1.0F);
	return FoliageColor::getBirchColor(temp, down);
}

int Biome::getEvergreenFoliageColor(const BlockPos& pos) const {
	float temp = mce::Math::clamp(getDefaultBiomeTemperature(), 0.0F, 1.0F);
	float down = mce::Math::clamp(getDownfall(), 0.0F, 1.0F);
	return FoliageColor::getEvergreenColor(temp, down);
}

int Biome::getMapBirchFoliageColor(const BlockPos& pos) const {
	float temp = mce::Math::clamp(getDefaultBiomeTemperature(), 0.0F, 1.0F);
	float down = mce::Math::clamp(getDownfall(), 0.0F, 1.0F);
	return FoliageColor::getMapBirchColor(temp, down);
}

int Biome::getMapEvergreenFoliageColor(const BlockPos& pos) const {
	float temp = mce::Math::clamp(getDefaultBiomeTemperature(), 0.0F, 1.0F);
	float down = mce::Math::clamp(getDownfall(), 0.0F, 1.0F);
	return FoliageColor::getMapEvergreenColor(temp, down);
}
