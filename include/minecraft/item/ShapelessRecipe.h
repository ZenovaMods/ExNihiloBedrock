#pragma once

#include "Recipe.h"

class ShapelessRecipe : public Recipe {
    const Ingredients mIngredients;
    const ResultList mResult;
};