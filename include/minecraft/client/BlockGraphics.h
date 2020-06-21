#pragma once

#include <vector>
#include <string>
#include <memory>

class BlockPalette;
namespace Json { class Value; }

enum class BlockShape : int {
    INVISIBLE = -1,
    BLOCK,
    CROSS_TEXTURE,
    TORCH,
    FIRE,
    WATER,
    RED_DUST,
    ROWS,
    DOOR,
    LADDER,
    RAIL,
    STAIRS,
    FENCE,
    LEVER,
    CACTUS,
    BED,
    DIODE,
    IRON_FENCE = 18,
    STEM,
    VINE,
    FENCE_GATE,
    CHEST,
    LILYPAD,
    BREWING_STAND = 25,
    PORTAL_FRAME,
    COCOA = 28,
    TREE = 31,
    WALL,
    DOUBLE_PLANT = 40,
    FLOWER_POT = 42,
    ANVIL,
    DRAGON_EGG,
    STRUCTURE_VOID = 48,
    BLOCK_HALF = 67,
    TOP_SNOW,
    TRIPWIRE,
    TRIPWIRE_HOOK,
    CAULDRON,
    REPEATER,
    COMPARATOR,
    HOPPER,
    SLIME_BLOCK,
    PISTON,
    BEACON,
    CHORUS_PLANT,
    CHORUS_FLOWER,
    END_PORTAL,
    END_ROD,
    END_GATEWAY,
    SKULL,
    FACING_BLOCK,
    COMMAND_BLOCK,
    TERRACOTTA,
    DOUBLE_SIDE_FENCE,
    ITEM_FRAME,
    SHULKER_BOX,
    DOUBLESIDED_CROSS_TEXTURE,
    DOUBLESIDED_DOUBLE_PLANT,
    DOUBLESIDED_ROWS,
    ELEMENT_BLOCK,
    CHEMISTRY_TABLE,
    CORAL_FAN = 96,
    SEAGRASS,
    KELP,
    TRAPDOOR,
    SEA_PICKLE,
    CONDUIT,
    TURTLE_EGG,
    BUBBLE_COLUMN = 105,
    BARRIER,
    SIGN,
    BAMBOO,
    BAMBOO_SAPLING,
    SCAFFOLDING,
    GRINDSTONE,
    BELL,
    LANTERN,
    CAMPFIRE,
    LECTERN,
    SWEET_BERRY_BUSH,
    CARTOGRAPHY_TABLE,
    COMPOSTER,
    STONE_CUTTER,
    HONEY_BLOCK
};

class BlockGraphics {
public:
    static std::vector<std::unique_ptr<BlockGraphics>>* mOwnedBlocks;

    static BlockGraphics& registerBlockGraphics(std::vector<Json::Value>&, const std::string&, BlockShape);
    static void registerLooseBlockGraphics(std::vector<Json::Value>&, const BlockPalette&);
};