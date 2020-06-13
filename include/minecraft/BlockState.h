#pragma once

#include <functional>
#include <string>
#include <initializer_list>

class CompoundTag;

class ItemState {
public:
    struct StateListNode {
        static StateListNode* mHead;
        StateListNode* mNext;
        StateListNode* mPrev;
        ItemState* mState;
    public:
        StateListNode(ItemState* state) : mNext(NULL), mPrev(NULL), mState(state) {
            if (mHead) {
                mHead->mPrev = this;
                mNext = mHead;
            }
            mHead = this;
        }
        ~StateListNode() {
            if (this == mHead) {
                mHead = mHead->mNext;
                if (mHead)
                    mHead->mPrev = NULL;
            }
            else if (mNext) {
                mPrev->mNext = mNext;
                mNext->mPrev = mPrev;
            }
            else {
                mPrev->mNext = NULL;
            }
        }
    };
protected:
    const size_t mID;
    const size_t mVariationCount;
    const std::string mName;
    ItemState::StateListNode mNode;

    ItemState(size_t id, const std::string& stateName, size_t variationCount)
        : mID(id), mVariationCount(variationCount), mName(stateName), mNode(this) { }
public:
    virtual ~ItemState() { }
    size_t getID() const { return mID; }
    size_t getVariationCount() const { return mVariationCount; }
    const std::string& getName() const { return mName; }
    virtual void toNBT(CompoundTag&, int) const;
    virtual int fromNBT(const CompoundTag&) const;
    static void forEachState(std::function<bool(const ItemState&)>);
};

template<typename T>
class ItemStateVariant : public ItemState {
public:
    ItemStateVariant(size_t id, const std::string& stateName, size_t variationCount)
        : ItemState(id, stateName, variationCount) { }
    ItemStateVariant(size_t, const std::string&, std::initializer_list<T>);
    virtual ~ItemStateVariant() { }
    virtual void toNBT(CompoundTag&, int) const;
    virtual int fromNBT(const CompoundTag&) const;
};

class ItemStateInstance {
private:
    const unsigned int mMaxBits;
    uint32_t mStartBit;
    uint32_t mNumBits;
    uint32_t mVariationCount;
    uint32_t mMask;
    bool mInitialized;
    const ItemState* mState;

public:
    ItemStateInstance();
    void initState(uint32_t&, uint32_t, uint32_t, const ItemState&);
    bool isInitialized() const { return mInitialized; }
    uint32_t getMask() const { return mMask; }
    uint32_t getNumBits() const { return mNumBits; }
    bool isValidData(uint32_t);
    const ItemState& getState() const { return *mState; }
};