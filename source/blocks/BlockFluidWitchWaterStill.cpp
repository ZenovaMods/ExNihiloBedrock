#include "BlockFluidWitchWaterStill.h"

#include "ENBlocks.h"

#include "minecraft/block/Block.h"
#include "minecraft/block/VanillaBlockStates.h"
#include "minecraft/world/BlockSource.h"
#include "minecraft/world/Level.h"
#include "minecraft/actor/Slime.h"
#include "minecraft/actor/ActorFactory.h"
#include "minecraft/actor/MobEffectInstance.h"

BlockFluidWitchWaterStill::BlockFluidWitchWaterStill(const std::string& nameId, int id) : LiquidBlockStatic(nameId, id, Material::getMaterial(MaterialType::Water)) {
    setDestroyTime(100.0F);
    setLightBlock(2);
    setCategory(CreativeItemCategory::DECORATIONS);
    addState(*VanillaStates::LiquidDepth);
    setAllowsRunes(true);
    addProperty(BlockProperty::Liquid);
    addProperty(BlockProperty::CanBeBuiltOver);
}

Color BlockFluidWitchWaterStill::getMapColor(BlockSource&, const BlockPos&) const {
    return { 0.125F, 0.0F, 0.322F, 1.0F };
}

void BlockFluidWitchWaterStill::entityInside(BlockSource& region, const BlockPos& pos, Actor& entity) const {
    EntityInWitchWater(region, pos, entity);
}

void BlockFluidWitchWaterStill::_setDynamic(BlockSource& region, const BlockPos& pos) const {
    bool usingExtraData = region.getBlock(pos).getLegacyBlock() != *this;
    auto& liquidBlock = region.getLiquidBlock(pos);
    int depth = liquidBlock.getState<int>(*VanillaStates::LiquidDepth);

    if (*this == liquidBlock.getLegacyBlock()) {
        const Block* dynamicLiquid = ENBlocks::blockWitchwaterFlowing->get()->getDefaultState().setState(*VanillaStates::LiquidDepth, depth);
        region.setLiquidBlock(pos, *dynamicLiquid, usingExtraData, 4);
        region.addToTickingQueue(pos, *dynamicLiquid, getTickDelay(region), 0);
    }
}

void EntityInWitchWater(BlockSource& region, const BlockPos& pos, Actor& entity) {
    Level& level = region.getLevel();
    if (level.isClientSide())
        return;

    if (!entity.isAlive())
        return;

    if (ActorClassTree::isInstanceOf(entity, ActorType::Skeleton)) {
        auto skeleton = level.getActorFactory().createTransformedEntity({ ActorType::WitherSkeleton }, &entity);
        if (skeleton) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(skeleton));
            if (addedEntity && entity.isPersistent())
                addedEntity->setPersistent();
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Creeper)) {
        if (!entity.isPowered()) {
            entity.setPowered(true);
            entity.serializationSetHealth(entity.getMaxHealth());

            return;
        }
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Spider)) {
        auto caveSpider = level.getActorFactory().createTransformedEntity({ ActorType::CaveSpider }, &entity);
        if (caveSpider) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(caveSpider));
            if (addedEntity && entity.isPersistent())
                addedEntity->setPersistent();
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Squid)) {
        auto ghast = level.getActorFactory().createTransformedEntity({ ActorType::Ghast }, &entity);
        if (ghast) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(ghast));
            if (addedEntity && entity.isPersistent())
                addedEntity->setPersistent();
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Pig)) {
        auto zombiePig = level.getActorFactory().createTransformedEntity({ ActorType::PigZombie }, &entity);
        if (zombiePig) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(zombiePig));
            if (addedEntity && entity.isPersistent())
                addedEntity->setPersistent();
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::VillagerBase)) {
        auto witch = level.getActorFactory().createTransformedEntity({ ActorType::Witch }, &entity);
        if (witch) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(witch));
            if (addedEntity && entity.isPersistent())
                addedEntity->setPersistent();
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Slime)) {
        auto slime = level.getActorFactory().createTransformedEntity({ ActorType::LavaSlime }, &entity);
        if (slime) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(slime));
            if (addedEntity) {
                dynamic_cast<Slime*>(addedEntity)->setSlimeSize(dynamic_cast<Slime&>(entity).getSlimeSize());
                if (entity.isPersistent())
                    addedEntity->setPersistent();
            }
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Cow)) {
        auto mooshroom = level.getActorFactory().createTransformedEntity({ ActorType::MushroomCow }, &entity);
        if (mooshroom) {
            Actor* addedEntity = level.addEntity(entity.getRegion(), std::move(mooshroom));
            if (addedEntity && entity.isPersistent())
                addedEntity->setPersistent();
        }
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::MushroomCow)) {
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Animal)) {
        entity.onLightningHit();
        return;
    }

    if (ActorClassTree::isInstanceOf(entity, ActorType::Player)) {
        entity.addEffect(MobEffectInstance(MobEffect::getByName("blindness")->getId(), 210, 0));
        entity.addEffect(MobEffectInstance(MobEffect::getByName("weakness")->getId(), 210, 2));
        entity.addEffect(MobEffectInstance(MobEffect::getByName("wither")->getId(), 210, 0));
        entity.addEffect(MobEffectInstance(MobEffect::getByName("slowness")->getId(), 210, 0));
    }
}
