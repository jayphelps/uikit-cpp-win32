#ifndef UIAPPLICATIONDELEGATE_H_
#define UIAPPLICATIONDELEGATE_H_
#pragma once

#include "../Foundation/Foundation.h"

#include "UIWindow.h"

class UIApplication;

class UIApplicationDelegate : public NSObject {
  public:
    UIWindow *window;

    UIApplicationDelegate();
    virtual ~UIApplicationDelegate();

    virtual void applicationDidFinishLaunching(UIApplication &);
};

// UIAPPLICATIONDELEGATE_H_
#endif