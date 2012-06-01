#ifndef CALAYER_H_
#define CALAYER_H_
#pragma once

#include "../Foundation/Foundation.h"
#include "../CoreGraphics/CoreGraphics.h"

class CALayer;
class UIColor;

class CALayerDelegateProtocol {
  public:
    virtual void drawLayerInContext(CALayer *) = 0;
};

class CALayer : public NSObject {
  public:
    property (getHidden, setHidden) BOOL isHidden;
    property (getNeedsDisplay, setNeedsDisplay) BOOL needsDisplay;
    CGRect frame;
    CGPoint position;
    //NSArray *sublayers;
    CALayer *superlayer;
    CALayerDelegateProtocol *delegate;
    UIColor *backgroundColor;

    CALayer();
    virtual ~CALayer();

    CALayer * init();
    CALayer * initWithLayer(CALayer *);
    CALayer * initWithFrame(CGRect);

    void addSublayer(CALayer *);
    void display();
    void drawInContext();

    BOOL getHidden();
    void setHidden(BOOL);
    BOOL getNeedsDisplay();
    void setNeedsDisplay(BOOL);

  protected:
    DWORD _dwStyle;
    HWND _hWnd;
    BOOL _needsDisplay;
};

// CALAYER_H_
#endif