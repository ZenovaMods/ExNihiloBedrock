#include "BlockBarrel.h"

BlockBarrel::BlockBarrel(const std::string& nameId, int id, int tier, MaterialType material) : BlockLegacy(nameId, id, Material::getMaterial(material)), tier(tier) {
	mRenderLayer = BlockRenderLayer::RENDERLAYER_OPAQUE;
	setSolid(false);
	setIsInteraction(true);
	mAnimatedTexture = true;
	mTranslucency = std::max(0.8f, mMaterial.getTranslucency());
	setDestroyTime(2.0f);
	setVisualShape({ 0.0625f, 0.0f, 0.0625f }, { 0.9375f, 1.0f, 0.9375f });
	setCategory(CreativeItemCategory::ITEMS);
}
