#pragma once

class ResourcePackManager;

class WorldSystems {
public:
    static bool* mInitialized;

    static void init(ResourcePackManager*);
    static void shutdown();
};

namespace VanillaWorldSystems {
    extern void shutdown();
}