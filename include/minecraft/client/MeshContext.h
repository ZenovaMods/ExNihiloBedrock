#pragma once

#include <memory>

class ShaderColor;

namespace mce {
    class RenderContext;
    class Camera;
    class GlobalConstantBuffers;
    class GlobalConstantBufferManager;
    class BufferResourceService;
    class QuadIndexBuffer;

    class MeshContext {
    public:
        RenderContext& mRenderContext;
        Camera& mCamera;
        GlobalConstantBuffers& mGlobalConstantBuffers;
        GlobalConstantBufferManager& mGlobalConstantBufferManager;
        ShaderColor& mShaderColor;
        ShaderColor& mDarkShaderColor;
        BufferResourceService& mBufferResourceService;
        QuadIndexBuffer& mQuadIndexBuffer;
        int64_t mResourceBlockTemplate[2];
        int64_t mFiller[2];
        int mIdk;
        unsigned char mSubClientId;
        char mIdk2;
        char mIdk3;
        char mIdk4;
    };
}