#pragma once

class ItemStackBase;

class Enchant {
public:
    enum class Type : int {
        MiningSilkTouch = 16,
        MiningDurability,
        MiningLoot,
    };
};

class EnchantUtils {
public:
    static int getEnchantLevel(Enchant::Type, const ItemStackBase&);
    static bool hasEnchant(Enchant::Type, const ItemStackBase&);
};