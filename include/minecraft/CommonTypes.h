#pragma once

#include <vector>
#include <memory>
#include <mutex>

#include "util/NewType.h"

class Actor;
class BlockActor;
class MobEffectInstance;
class Player;


template <typename T>
using Unique = std::unique_ptr<T>;

template <typename T>
using Shared = std::shared_ptr<T>;

template <typename T>
using Weak = std::weak_ptr<T>;

typedef std::vector<Actor*> ActorList;
typedef std::vector<BlockActor*> BlockActorList;
typedef std::vector<std::unique_ptr<Actor>> OwnedActorList;
typedef std::vector<Player*> PlayerList;

typedef std::vector<MobEffectInstance> MobEffectInstanceList;

typedef std::lock_guard<std::mutex> LockGuard;
typedef std::unique_lock<std::mutex> ScopedLock;

typedef unsigned char SubClientId;

typedef unsigned int RandomSeed;

typedef short Height;

typedef unsigned char FacingID;

typedef unsigned int BlockRuntimeId;

struct NewBlockID : public NewType<unsigned short> {
public:
    NewBlockID();
    NewBlockID(const Raw&);
};

struct BlockID : public NewType<unsigned char> {
public:
    BlockID();
    BlockID(const Raw&);
};

struct Brightness : public NewType<unsigned char> {
    static const Brightness MAX;
    static const Brightness MIN;
    static const Brightness INVALID;
    static Raw NUM_VALUES;
public:
    Brightness(const Raw& v) : NewType<unsigned char>(v) { }

    Brightness() : Brightness(MIN) { }

    Brightness& operator-=(const Brightness& rhs) {
        value -= rhs.value;
        return *this;
    }
    Brightness& operator+=(const Brightness& rhs) {
        value += rhs.value;
        return *this;
    }
};

inline const Brightness Brightness::MAX{ 15 };
inline const Brightness Brightness::MIN{ 0 };
inline const Brightness Brightness::INVALID{ 0xFF };

struct BrightnessPair {
    Brightness sky;
    Brightness block;
public:
    BrightnessPair(Brightness sky, Brightness block)
        : sky(sky), block(block) { }
};

typedef unsigned short DataID;

enum class Side : int {
    Left,
    Right
};

enum class CompactionStatus : int {
    Starting,
    Finished
};

namespace Social {
    typedef unsigned int LocalUserId;
}

//constexpr helpers to make the code look neater
template <std::size_t N>
constexpr auto BitFlag = (1 << N);