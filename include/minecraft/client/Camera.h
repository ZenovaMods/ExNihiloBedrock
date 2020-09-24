#pragma once

#include <vector>

#include "MatrixStack.h"
#include "../util/Vec3.h"

struct Frustum {
    char filler[0xC0];
};

namespace mce {
    class Camera {
    public:
        MatrixStack mModel, mWorld, mProjection;
        Matrix mView;
        Vec3 mRightVector, mUpVector, mForwardVector, mPosition;
        float mAspectRatio;
        float mFov;
        float mNearClip;
        float mFarClip;
        Frustum mFrustum;

        glm::mat4 getModelViewMatrix() {
            return mModel.top() * mWorld.top();
        }

        glm::mat4 getModelViewProjectionMatrix() {
            return (mProjection.top() * mModel.top()) * mWorld.top();
        }

        const Vec3& getPosition() const {
            return mPosition;
        }

        const Vec3& getRightVector() const {
            return mRightVector;
        }

        const Vec3& getUpVector() const {
            return mUpVector;
        }

        const Vec3& getForwardVector() const {
            return mForwardVector;
        }

        bool isOrthographic() const {
            return std::fabs(mProjection.top()[3][3] + -1.0f) < std::numeric_limits<float>::epsilon();
        }
    };
}