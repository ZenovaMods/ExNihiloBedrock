#pragma once

#include <unordered_map>
#include <functional>

#include "OnHitSubcomponent.h"

class Level;

class ProjectileFactory {
public:
    Level& mLevel;
    static std::unordered_map<std::string, std::function<std::unique_ptr<OnHitSubcomponent>()>>& mSubcomponentMap;

    ProjectileFactory(Level& level) : mLevel(level) {}
    static void initFactory();
};