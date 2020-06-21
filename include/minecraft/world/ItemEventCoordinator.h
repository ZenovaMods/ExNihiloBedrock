#pragma once

class ItemInstance;
class Actor;

class ItemEventCoordinator {
public:
    void onItemSpawnedActor(const ItemInstance&, const Actor&);
};