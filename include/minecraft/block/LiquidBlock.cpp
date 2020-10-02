#include "LiquidBlock.h"

#include "../world/BlockSource.h"
#include "../world/Dimension.h"

LiquidBlock::LiquidBlock(const std::string& nameId, int id, const Material& material) : BlockLegacy(nameId, id, material) {
    setSolid(false);
    mRenderLayer = material.isType(MaterialType::Water) ? BlockRenderLayer::RENDERLAYER_BLEND : BlockRenderLayer::RENDERLAYER_OPAQUE;
    mRenderLayerCanRenderAsOpaque = true;
    mProperties = BlockProperty::BreakOnPush;
    mCanInstatick = true;
    mAnimatedTexture = true;
    mTranslucency = 0.0f;
    setRandomTickingExtraLayer(material.isType(MaterialType::Water));
}

int LiquidBlock::getTickDelay(BlockSource& region) const {
    if (mMaterial.isType(MaterialType::Water))
        return 10;
    if (mMaterial.isType(MaterialType::Lava))
        return region.getDimensionConst().isUltraWarm() ? 10 : 30;
    return 0;
}
