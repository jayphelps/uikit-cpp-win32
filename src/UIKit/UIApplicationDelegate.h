#ifndef UIAPPLICATIONDELEGATE_H_
#define UIAPPLICATIONDELEGATE_H_
#pragma once

#include "../Foundation/Foundation.h"

#include "UIWindow.h"

class UIApplication;

class UIApplicationDelegate : public NSObject {
  public:
    UIWindow *window;

    virtual void applicationDidFinishLaunching(UIApplication &) = 0;
};

// UIAPPLICATIONDELEGATE_H_
#endif