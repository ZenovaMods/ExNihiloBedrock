#include "PebbleRenderer.h"

#include "minecraft/actor/Actor.h"
#include "minecraft/item/Item.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/client/ActorRenderData.h"
#include "minecraft/client/BaseActorRenderContext.h"
#include "ProjectileStone.h"

void PebbleRenderer::onAppSuspended() {
	for (auto& mesh : mTextureMeshes)
		mesh.reset();
}

void PebbleRenderer::render(BaseActorRenderContext& renderContext, ActorRenderData& renderData) {
	Actor& actor = renderData.getActor();
	if (&actor) {
		short auxValue = 0;
		if (actor.hasType(ActorType::Pebble))
			auxValue = dynamic_cast<ProjectileStone&>(actor).getStoneType();
		mce::Mesh* rendered = &mTextureMeshes[auxValue];
		if (!rendered->isValid())
			_buildQuad(renderContext, actor, *rendered);
		_renderQuad(renderContext, actor, *rendered, renderData.getPos(), renderData.mEntityYaw, renderContext.mPartialTicks);
	}
}

const TextureUVCoordinateSet& PebbleRenderer::getIcon(Actor& actor) const {
	short auxValue = 0;
	if (actor.hasType(ActorType::Pebble))
		auxValue = dynamic_cast<ProjectileStone&>(actor).getStoneType();
	return mItem->getIcon(ItemStack(*mItem, 1, auxValue), 0, false);
}