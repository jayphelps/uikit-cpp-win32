#pragma once

#include <Foundation/Foundation.h>

class UIView : public NSObject {
  public:
    std::vector<UIView *> subviews;
    CGRect frame;
    BOOL needsDisplay;

    UIView();
    virtual ~UIView();

    virtual UIView * initWithFrame(CGRect);
    virtual UIView * _initWithFrame(CGRect);
    virtual void addSubview(UIView *);
    virtual BOOL drawRect(CGRect);
};