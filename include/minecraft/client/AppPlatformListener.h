#pragma once

enum class OperationMode : int;

class AppPlatform;
class PushNotificationMessage;

class AppPlatformListener {
    AppPlatform* platform;

public:
    virtual ~AppPlatformListener();
    virtual void onLowMemory() {}
    virtual void onAppPaused() {}
    virtual void onAppUnpaused() {}
    virtual void onAppPreSuspended() {}
    virtual void onAppSuspended() {}
    virtual void onAppResumed() {}
    virtual void onAppFocusLost() {}
    virtual void onAppFocusGained() {}
    virtual void onAppTerminated() {}
    virtual void onOperationModeChanged(const OperationMode) {}
    virtual void onPerformanceModeChanged(const bool) {}
    virtual void onPushNotificationReceived(const PushNotificationMessage&) {}
    virtual void onResizeBegin() {}
    virtual void onResizeEnd() {}
};