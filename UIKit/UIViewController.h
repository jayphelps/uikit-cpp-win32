#pragma once

#include <Foundation/Foundation.h>

class UIViewController : public NSObject {
  public:
    UIView *view;

    UIViewController();
    virtual ~UIViewController();

    virtual void loadView();
    virtual void viewDidLoad();
};