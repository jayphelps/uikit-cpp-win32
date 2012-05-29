#ifndef UIVIEWCONTROLLER_H_
#define UIVIEWCONTROLLER_H_
#pragma once

#include "Foundation/Foundation.h"

#include "UIView.h"

class UIViewController : public NSObject {
  private:
    UIView *_view;

  public:
    property <UIViewController, UIView *> view;
    
    UIView * getView() {
        return this->_view;
    }

    void setView(UIView *view) {
        printf("MANLY DICK!!\n");
        this->_view = view;
    }

    UIViewController();
    virtual ~UIViewController();

    virtual void loadView();
    virtual void viewDidLoad();
};

// UIVIEWCONTROLLER_H_
#endif