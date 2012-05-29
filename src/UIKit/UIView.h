#ifndef UIVIEW_H_
#define UIVIEW_H_
#pragma once

#include "Foundation/Foundation.h"
#include "CoreGraphics/CoreGraphics.h"

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
    virtual void drawRect(CGRect);
};

// UIVIEW_H_
#endif