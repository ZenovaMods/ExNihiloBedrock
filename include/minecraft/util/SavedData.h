#pragma once

#include <string>

class CompoundTag;

class SavedData {
    bool mDirty = false;
    std::string mId;

public:
    SavedData(const std::string& id) : mId(id) {}
    virtual ~SavedData() {}
    virtual void deserialize(const CompoundTag&) = 0;
    virtual void serialize(CompoundTag&) const = 0;
    void setDirty(bool dirty) { mDirty = dirty; }
    bool isDirty() const { return mDirty; }
    const std::string& getId() const { return mId; }
};