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
    UIView *superview;
    CALayer *layer;
    UIViewController *_viewController;

    UIView();
    virtual ~UIView();

    virtual UIView * initWithFrame(CGRect);
    virtual UIView * _initWithFrame(CGRect);

    virtual void addSubview(UIView *);
    virtual void drawLayerInContext(CALayer *, CGContextRef);
    virtual void drawRect(CGRect);

    virtual BOOL getHidden();
    virtual void setHidden(BOOL);
    virtual BOOL getNeedsDisplay();
    virtual void setNeedsDisplay(BOOL);
    virtual CGRect getFrame();
    virtual void setFrame(CGRect);
    virtual UIColor * getBackgroundColor();
    virtual void setBackgroundColor(UIColor *);

};

// UIVIEW_H_
#endif