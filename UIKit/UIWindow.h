#pragma once

#include <Foundation/Foundation.h>

#include "UIView.h"
#include "UIViewController.h"

class UIWindow : public UIView {
  public:
    UIViewController *rootViewController;
    
    virtual UIWindow * initWithFrame(CGRect);
    virtual void makeKeyAndVisible();
};