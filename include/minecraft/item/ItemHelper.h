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