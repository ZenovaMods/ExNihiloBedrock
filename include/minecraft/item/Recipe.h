#pragma once

#include <vector>

#include "../util/Util.h"
#include "ItemDescriptorCount.h"


class RecipeIngredient : public ItemDescriptorCount {
public:
    static RecipeIngredient EMPTY_INGREDIENT;

    RecipeIngredient() : ItemDescriptorCount() {}
    RecipeIngredient(const ItemDescriptor& descriptor, uint16_t stackSize) : ItemDescriptorCount(descriptor, stackSize) {}
    RecipeIngredient(const Block& block, uint16_t stackSize) : ItemDescriptorCount(block, stackSize) {}
    RecipeIngredient(const BlockLegacy& block, uint16_t stackSize) : ItemDescriptorCount(block, stackSize) {}
    RecipeIngredient(const Item& item, int auxValue, uint16_t stackSize) : ItemDescriptorCount(item, auxValue, stackSize) {}
};

inline RecipeIngredient RecipeIngredient::EMPTY_INGREDIENT{};

class Recipe {
public:
    typedef std::vector<RecipeIngredient> Ingredients;
    typedef std::vector<ItemInstance> ResultList;

protected:
    std::string mRecipeId;
    char mMyItems[0x38];
    char mMyId[0x10];
    int mWidth;
    int mHeight;
    int mPriority;
private:
    Ingredients mMyIngredients;
    Util::HashString mTag;

public:
    virtual ~Recipe();
};