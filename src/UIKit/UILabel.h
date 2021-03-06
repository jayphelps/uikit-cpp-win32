#ifndef UILABEL_H_
#define UILABEL_H_
#pragma once

#include "../Foundation/Foundation.h"
#include "../CoreGraphics/CoreGraphics.h"

#include "UIView.h"
#include "UIStringDrawing.h"
#include "UIFont.h"

class UIColor;

class UILabel : public UIView {
  public:
    property (getText, setText) std::wstring text;
    property (getTextColor, setTextColor) UIColor *textColor;
    property (getShadowColor, setShadowColor) UIColor *shadowColor;
    property (getShadowOffset, setShadowOffset) CGSize shadowOffset;
    
    UIFont font;
    int textAlignment;

    UILabel();
    virtual ~UILabel();

    virtual UILabel * initWithFrame(CGRect);

    virtual void drawRect(CGRect);

    virtual std::wstring getText();
    virtual void setText(std::wstring);
    virtual UIColor * getTextColor();
    virtual void setTextColor(UIColor *);
    virtual UIColor * getShadowColor();
    virtual void setShadowColor(UIColor *);
    virtual CGSize getShadowOffset();
    virtual void setShadowOffset(CGSize);

  protected:
    std::wstring _text;
    UIColor *_textColor;
    UIColor *_shadowColor;
    CGSize _shadowOffset;
};

// UILABEL_H_
#endif