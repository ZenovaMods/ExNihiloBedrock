#pragma once

#include <cstdint>

namespace Bedrock {
    namespace Application {
        template<class T>
        class ThreadOwner {
        private:
            T mObject;

        public:
            ThreadOwner();
            ThreadOwner(T&&);
            ThreadOwner(const ThreadOwner<T>&);
            ThreadOwner<T>& operator=(const ThreadOwner<T>&);
            ThreadOwner<T>& operator=(const T&);
            T& get() {
                return mObject;
            }
            const T& get() const {
                return mObject;
            }
        };
    }
}

namespace Core {
    class Random {
    private:
        typedef uint32_t result_type;

        result_type mSeed;
        result_type _mt[624];
        int _mti;
        bool mHaveNextNextGaussian;
        float mNextNextGaussian;
        int mInitedIdx;
    public:
        int nextInt(int n) {
            if (n)
                return _genRandInt32() % n;
            else
                return 0;
        }
    private:
        result_type _genRandInt32();
    };
}

class Random {
private:
    Bedrock::Application::ThreadOwner<Core::Random> mRandom;

public:
    int nextInt(int n) {
        return mRandom.get().nextInt(n);
    }
};