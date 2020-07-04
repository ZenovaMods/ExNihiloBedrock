#pragma once

#include <cstddef> 

#include "../CommonTypes.h"

enum class ActorCategory : unsigned int {
    None,
    Player = BitFlag<0>,
    Mob = BitFlag<1>,
    Monster = BitFlag<2>,
    Humandoid = BitFlag<3>,
    Animal = BitFlag<4>,
    WaterSpawning = BitFlag<5>,
    Pathable = BitFlag<6>,
    Tamable = BitFlag<7>,
    Ridable = BitFlag<8>,
    Item = BitFlag<10>,
    Ambient = BitFlag<11>,
    Villager = BitFlag<12>,
    Arthropod = BitFlag<13>,
    Undead = BitFlag<14>,
    Zombie = BitFlag<15>,
    Minecart = BitFlag<16>,
    Boat = BitFlag<17>,
    NonTargetable = BitFlag<18>,
    BoatRideable = Boat | Ridable,
    MinecartRidable = Minecart | Ridable,
    HumanoidMonster = Humandoid | Monster,
    WaterAnimal = WaterSpawning | Animal,
    TamableAnimal = Tamable | Animal,
    UndeadMob = Undead | Mob,
    ZombieMonster = Zombie | Monster,
    EvocationIllagerMonster = Villager | Monster | Humandoid
};