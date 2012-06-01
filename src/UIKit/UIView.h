#ifndef UIVIEW_H_
#define UIVIEW_H_
#pragma once

#include "../Foundation/Foundation.h"
#include "../CoreGraphics/CoreGraphics.h"

#include "../QuartzCore/CALayer.h"

class UIColor;
class UIViewController;

class UIView : public NSObject, public CALayerDelegateProtocol {
  public:
    property (getHidden, setHidden) BOOL isHidden;
    property (getFrame, setFrame) CGRect frame;
    property (getNeedsDisplay, setNeedsDisplay) BOOL needsDisplay;
    property (getBackgroundColor, setBackgroundColor) UIColor *backgroundColor;

    std::vector<UIView *> _subviews;
    CALayer *layer;
    UIViewController *_viewController;

    UIView();
    virtual ~UIView();

    virtual UIView * initWithFrame(CGRect);
    virtual UIView * _initWithFrame(CGRect);
    virtual void addSubview(UIView *);
    void drawLayerInContext(CALayer *);
    virtual BOOL drawRect(CGRect);

    BOOL getHidden();
    void setHidden(BOOL);
    BOOL getNeedsDisplay();
    void setNeedsDisplay(BOOL);
    CGRect getFrame();
    void setFrame(CGRect);
    UIColor * getBackgroundColor();
    void setBackgroundColor(UIColor *);

};

// UIVIEW_H_
#endif