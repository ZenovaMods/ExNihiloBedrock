#pragma once

#include <map>
#include <memory>

#include "ShapedRecipe.h"
#include "ShapelessRecipe.h"
#include "ItemStack.h"

class Item;
class Block;
class BlockLegacy;
class ResourcePackManager;

namespace Json { class Value; }

typedef std::vector<std::pair<std::weak_ptr<bool>, std::function<void()>>> RecipeListenerList;
typedef std::map<std::string, std::unique_ptr<Recipe>> RecipeMap;
typedef std::vector<std::string> RowList;
typedef std::function<std::unique_ptr<ShapedRecipe>(std::string, int, int, const std::vector<RecipeIngredient>&, const std::vector<ItemInstance>&, Util::HashString)> ShapedRecipeConstructor;
typedef std::function<std::unique_ptr<ShapelessRecipe>(std::string, const std::vector<RecipeIngredient>&, const std::vector<ItemInstance>&, Util::HashString)> ShapelessRecipeConstructor;

class Recipes {
public:
    struct FurnaceRecipeKey {
        int mID;
        Util::HashString mTag;

        FurnaceRecipeKey(int idAux, const Util::HashString& tag) : mID(idAux), mTag(tag) {}
        bool operator<(const FurnaceRecipeKey& rhs) const {
            if (mID == rhs.mID)
                return mTag < rhs.mTag;
            return mID < rhs.mID;
        }
    };

    class Type {
    public:
        Item* mItem = nullptr;
        const Block* mBlock = nullptr;
        RecipeIngredient mIngredient;
        char mC;

        Type(char c, Item* item) : mItem(item), mC(c) {}
        Type(char c, const Block* block) : mBlock(block), mC(c) {}
        Type(char c, const BlockLegacy* block) : mIngredient(*block, 1), mC(c) {}
        Type(char c, const RecipeIngredient& ingredient) : mIngredient(ingredient), mC(c) {}
    };

    typedef std::vector<Type> TypeList;

private:
    ResourcePackManager* mResourcePackManager;
    std::map<Util::HashString, std::map<std::string, std::unique_ptr<Recipe>>> mRecipes;
    std::map<FurnaceRecipeKey, ItemInstance> mFurnaceRecipes;
    bool mInitializing;
    std::map<ItemInstance, std::unordered_map<std::string, Recipe*>, SortItemInstanceIdAux> mRecipesByOutput;
    RecipeListenerList mListeners;

public:
    const RecipeMap& getRecipes(const Util::HashString&) const;
    const std::map<Util::HashString, std::map<std::string, std::unique_ptr<Recipe>>>& getRecipesAllTags() const { return mRecipes; }
    const std::map<FurnaceRecipeKey, ItemInstance>& getFurnaceRecipes() const { return mFurnaceRecipes; }
    bool loadRecipes(ResourcePackManager&);
    bool loadRecipe(const Json::Value&);
    static RowList Shape(const std::string& r0) {
        RowList ret;
        ret.push_back(r0);
        return ret;
    }
    static RowList Shape(const std::string& r0, const std::string& r1) {
        RowList ret;
        ret.push_back(r0);
        ret.push_back(r1);
        return ret;
    }
    static RowList Shape(const std::string& r0, const std::string& r1, const std::string& r2) {
        RowList ret;
        ret.push_back(r0);
        ret.push_back(r1);
        ret.push_back(r2);
        return ret;
    }
    ~Recipes();
    void clearRecipes();
    void init(ResourcePackManager&);
    void addShapedRecipe(std::string recipeId, const ItemInstance& result, const std::string& r0, const TypeList& types, const std::vector<Util::HashString>& tags, const int priority, ShapedRecipeConstructor ctor);
    void addShapedRecipe(std::string recipeId, const ItemInstance& result, const std::string& r0, const std::string& r1, const TypeList& types, const std::vector<Util::HashString>& tags, const int priority, ShapedRecipeConstructor ctor);
    void addShapedRecipe(std::string recipeId, const ItemInstance& result, const std::string& r0, const std::string& r1, const std::string& r2, const TypeList& types, const std::vector<Util::HashString>& tags, const int priority, ShapedRecipeConstructor ctor);
    void addShapedRecipe(std::string recipeId, const ItemInstance& result, const RowList& rows, const TypeList& types, const std::vector<Util::HashString>& tags, const int priority, ShapedRecipeConstructor ctor);
    void addShapedRecipe(std::string recipeId, const Recipe::ResultList& result, const RowList& rows, const TypeList& types, const std::vector<Util::HashString>& tags, const int priority, ShapedRecipeConstructor ctor);
    void addSingleIngredientRecipeItem(std::string recipeId, const ItemInstance& result, const RecipeIngredient&, const std::vector<Util::HashString>& tags);
    void addShapelessRecipe(std::string recipeId, const ItemInstance& result, const TypeList&, const std::vector<Util::HashString>& tags, const int priority, ShapelessRecipeConstructor ctor);
    void addDirectShapelessRecipe(Unique<ShapelessRecipe>);
    void addDirectShapedRecipe(Unique<ShapedRecipe>);
    void addShulkerBoxRecipe(std::string&, const ItemInstance&, const TypeList&, const std::vector<Util::HashString>&);
    Recipe* getRecipeFor(const ItemInstance&, const Util::HashString&) const;
    std::vector<Recipe*> getAllRecipesFor(const ItemInstance&, const Util::HashString&) const;
    void addRecipeListener(std::weak_ptr<bool>, std::function<void()>);
    void removeRecipeListener(std::weak_ptr<bool>);
    void notifyRecipeListeners();
    void addFurnaceRecipeAuxData(const ItemInstance& input, const ItemInstance& result, const std::vector<Util::HashString>& tags);
    ItemInstance getFurnaceRecipeResult(const ItemInstance&, const Util::HashString&) const;
private:
    const RecipeIngredient _loadIngredientFromJson(const Json::Value&) const;
    ItemInstance _itemInstanceFromIngredient(const RecipeIngredient&) const;
    void _addMapRecipes();
    void _addItemRecipe(std::unique_ptr<Recipe>);
};