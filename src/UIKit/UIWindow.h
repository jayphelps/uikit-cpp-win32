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
    
    UIViewController * getRootViewController() {
        return this->_rootViewController;
    }

    void setRootViewController(UIViewController *controller) {
        this->_rootViewController = controller;
    }

    UIWindow();
    virtual UIWindow * initWithFrame(CGRect);
    virtual void makeKeyAndVisible();
};

// UIWINDOW_H_
#endif