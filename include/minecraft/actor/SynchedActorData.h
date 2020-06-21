#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "../util/Vec3.h"

class Actor;
class CompoundTag;

enum class DataItemType : unsigned char {
    Byte,
    Short,
    Int,
    Float,
    String,
    CompoundTag,
    Pos,
    Int64,
    Vec3,
    Unknown
};

class DataItem {
public:
    typedef unsigned short ID;

protected:
    const DataItemType mType;
    ID mId;
    bool mDirty = true;

public:
    DataItem(DataItemType type, ID id) : mType(type), mId(id) {}
    virtual ~DataItem() {}
    ID getId() const { return mId; }
    DataItemType getType() const { return mType; }
    bool isDirty() const { return mDirty; }
    void setDirty(bool dirty) { mDirty = dirty; }
    virtual bool isDataEqual(const DataItem& rhs) const {
        return mType == rhs.mType;
    }
    virtual std::unique_ptr<DataItem> clone() const = 0;
};

template<typename T>
class DataItem2 : public DataItem {
public:
    T mData;

    DataItem2(DataItemType type, ID id, const T& data) : DataItem(type, id), mData(data) {}
    virtual std::unique_ptr<DataItem> clone() const {
        return std::make_unique<DataItem2>(mType, mId, mData);
    }
};

namespace DataTypeMap {
    template<typename T>
    struct neqFor {
        static bool neq(const T& a, const T& b) {
            return &a != &b;
        }
    };
    template<typename T>
    struct copyFor {
        static void copy(T& dst, const T& src) {
            dst = src;
        }
    };
    template<typename T>
    struct typeFor {};

    template<>
    struct typeFor<int8_t> {
        operator DataItemType() const {
            return DataItemType::Byte;
        }
    };
    template<>
    struct typeFor<short> {
        operator DataItemType() const {
            return DataItemType::Short;
        }
    };
    template<>
    struct typeFor<int> {
        operator DataItemType() const {
            return DataItemType::Int;
        }
    };
    template<>
    struct typeFor<float> {
        operator DataItemType() const {
            return DataItemType::Float;
        }
    };
    template<>
    struct typeFor<std::string> {
        operator DataItemType() const {
            return DataItemType::String;
        }
    };
    template<>
    struct typeFor<int64_t> {
        operator DataItemType() const {
            return DataItemType::Int64;
        }
    };
}

class SynchedActorData {
    typedef std::vector<std::unique_ptr<DataItem>> DataList;
    typedef DataItem::ID ID;
    typedef int8_t TypeInt8;
    typedef short TypeShort;
    typedef int TypeInt;
    typedef int64_t TypeInt64;
    typedef float TypeFloat;
    typedef Vec3 TypeVec3;

public:
    static TypeInt MAX_STRING_DATA_LENGTH;
    static TypeInt EOF_MARKER;
private:
    DataList mItemsArray;
    ID minIdxDirty = std::numeric_limits<unsigned short>::max();
    ID maxIdxDirty = std::numeric_limits<unsigned short>::min();
    static TypeInt TYPE_MASK;
    static TypeInt TYPE_SHIFT;
    static TypeInt MAX_ID_VALUE;

public:
    SynchedActorData() = default;
    TypeInt8 getInt8(ID id) const {
        DataItem2<TypeInt8>* dataItem = dynamic_cast<DataItem2<TypeInt8>*>(_find(id));
        if (dataItem && dataItem->getType() == DataItemType::Byte)
            return dataItem->mData;
        return 0;
    }
    TypeShort getShort(ID id) const {
        DataItem2<TypeShort>* dataItem = dynamic_cast<DataItem2<TypeShort>*>(_find(id));
        if (dataItem && dataItem->getType() == DataItemType::Short)
            return dataItem->mData;
        return 0;
    }
    TypeInt getInt(ID id) const {
        DataItem2<TypeInt>* dataItem = dynamic_cast<DataItem2<TypeInt>*>(_find(id));
        if (dataItem && dataItem->getType() == DataItemType::Int)
            return dataItem->mData;
        return 0;
    }
    TypeInt64 getInt64(ID id) const {
        DataItem2<TypeInt64>* dataItem = dynamic_cast<DataItem2<TypeInt64>*>(_find(id));
        if (dataItem && dataItem->getType() == DataItemType::Int64)
            return dataItem->mData;
        return 0;
    }
    TypeFloat getFloat(ID id) const {
        DataItem2<TypeFloat>* dataItem = dynamic_cast<DataItem2<TypeFloat>*>(_find(id));
        if (dataItem && dataItem->getType() == DataItemType::Float)
            return dataItem->mData;
        return 0.0F;
    }
    const std::string& getString(ID id) const {
        DataItem2<std::string>* dataItem = dynamic_cast<DataItem2<std::string>*>(_find(id));
        if (dataItem && dataItem->getType() == DataItemType::String)
            return dataItem->mData;
        return "";
    }
    bool hasData(ID id) const { return _find(id) != nullptr; }
    void markDirty(DataItem& item) {
        item.setDirty(true);
        _setDirty(item.getId());
    }
    void markDirty(ID id) {
        markDirty(_get(id));
    }
    bool isDirty() const {
        return minIdxDirty <= maxIdxDirty;
    }
private:
    void _setDirty(ID id) {
        minIdxDirty = std::min<ID>(id, minIdxDirty);
        maxIdxDirty = std::max<ID>(id, maxIdxDirty);
    }
    DataItem& _get(ID id) {
        return *mItemsArray[id];
    }
    DataItem* _find(ID id) const {
        if (id >= mItemsArray.size())
            return nullptr;

        return mItemsArray[id].get();
    }
    void _resizeToContain(ID id) {
        while (mItemsArray.size() <= id) {
            mItemsArray.emplace_back(nullptr);
        }
    }
public:
    template<typename T>
    void define(ID id, const T& value) {
        DataTypeMap::typeFor<T> type;
        if ((id <= 0x1FFF) && !_find(id)) {
            _resizeToContain(id);
            mItemsArray[id] = std::make_unique<DataItem2<T>>(type, id, value);
            _setDirty(id);
        }
    }

    template<typename T>
    void set(ID id, const T& value) {
        set<T>(&_get(id), value);
    }
    template<typename T>
    void set(DataItem* dataItem, const T& value) {
        T& validType = reinterpret_cast<DataItem2<T>*>(dataItem)->mData;
        if (dataItem && (dataItem->getType() == DataTypeMap::typeFor<T>()) && DataTypeMap::neqFor<T>::neq(validType, value)) {
            DataTypeMap::copyFor<T>::copy(validType, value);
            markDirty(*dataItem);
        }
    }
};