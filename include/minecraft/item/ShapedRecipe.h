#pragma once

#include "Recipe.h"

class ShapedRecipe : public Recipe {
    Ingredients mIngredients;
    ResultList mResults;

public:
    virtual ~ShapedRecipe();
};