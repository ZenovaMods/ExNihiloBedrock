#pragma once

enum class ItemUseMethod : int {
    Unknown = -1,
    EquipArmor,
    Eat,
    Attack,
    Consume,
    Throw,
    Shoot,
    Place,
    FillBottle,
    FillBucket,
    PourBucket,
    UseTool,
    Interact,
    Retrieved,
    Dyed,
    Traded,
    _Count
};

enum class ItemAcquisitionMethod : int {
    Unknown = -1,
    None,
    PickedUp,
    Crafted,
    TakenFromChest,
    TakenFromEnderchest,
    Bought,
    Anvil,
    Smelted,
    Brewed,
    Filled,
    Trading,
    Fishing,
    Container = 13
};