#ifndef UIWINDOW_H_
#define UIWINDOW_H_
#pragma once

#include "Foundation/Foundation.h"

#include "UIView.h"
#include "UIViewController.h"

class UIWindow : public UIView {
  private:
    UIViewController *_rootViewController;

  public:
    property <UIWindow, UIViewController *> rootViewController;
    UIViewController * getRootViewController();
    void setRootViewController(UIViewController *);

    UIWindow();
    virtual UIWindow * initWithFrame(CGRect);
    virtual void makeKeyAndVisible();
};

// UIWINDOW_H_
#endif