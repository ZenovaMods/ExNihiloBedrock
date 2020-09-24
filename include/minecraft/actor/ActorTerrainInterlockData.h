#pragma once

#include <chrono>

class ActorTerrainInterlockData {
public:
    enum class VisibilityState : unsigned char {
        InitialNotVisible,
        Visible,
        DelayedDestructionNotVisible
    };

protected:
    VisibilityState mRenderVisibilityState;
    std::chrono::system_clock::time_point mCreationTime;
    bool mHasBeenDelayedDeleted;

public:
    ActorTerrainInterlockData();
    std::chrono::system_clock::time_point getCreationTime() const;
    VisibilityState getRenderVisibilityState() const;
    void setRenderVisibilityState(VisibilityState);
    void setCreationTime();
    void setHasBeenDelayedDeleted();
    bool getHasBeenDelayedDeleted() const;
};