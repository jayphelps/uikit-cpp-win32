#ifndef UIVIEWCONTROLLER_H_
#define UIVIEWCONTROLLER_H_
#pragma once

#include "../Foundation/Foundation.h"

#include "UIResponder.h"
#include "UIView.h"

class UIViewController : public UIResponder {
  public:
    property (getView, setView) UIView *view;
    UIView * getView();
    void setView(UIView *);

    UIViewController();
    virtual ~UIViewController();

    virtual void loadView();
    virtual void viewDidLoad();
    virtual void viewWillAppear();
    virtual void viewDidAppear();
    virtual void viewWillDisappear();
    virtual void viewDidDisappear();
    
  private:
    UIView *_view;
};

// UIVIEWCONTROLLER_H_
#endif