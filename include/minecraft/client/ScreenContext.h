#pragma once

#include "MeshContext.h"

class CommandListQueue;
class FrameRenderObject;
class GuiData;
class MinecraftGraphicsPipeline;
class MinecraftGraphics;
class Tessellator;
class UIProfanityContext;

namespace mce {
    class Clock;
    class RenderDevice;
    class RendererSettings;
    class ViewportInfo;
}

class UIScreenContext {
    int mWidth;
    int mHeight;
    float mScale;
};

class ScreenContext {
public:
    UIScreenContext mUIContext;
    mce::MeshContext mMeshContext;
    mce::RenderDevice& mRenderDevice;
    mce::RendererSettings& mRenderSettings;
    void* mFiller;
    const mce::ViewportInfo& mViewportInfo;
    const GuiData& mGuiData;
    const mce::Clock& mClock;
    Tessellator& mTessellator;
    MinecraftGraphicsPipeline& mGraphicsPipeline;
    MinecraftGraphics& mGraphics;
    const UIProfanityContext& mProfanityContext;
    CommandListQueue& mCommandListQueue;
    std::allocator<FrameRenderObject>& mFrameRenderObject;  // should be LinearAllocator but I'm lazy :P

    ScreenContext(mce::RenderDevice&, mce::RendererSettings&, const mce::ViewportInfo&,
        const GuiData&, const mce::Clock&, Tessellator&,
        MinecraftGraphicsPipeline&, MinecraftGraphics&, const UIProfanityContext&,
        CommandListQueue&, std::allocator<FrameRenderObject>&, mce::MeshContext&,
        int width, int height, float scale);
};