#ifndef UICOLOR_H_
#define UICOLOR_H_
#pragma once

#include "../Foundation/Foundation.h"
#include "../CoreGraphics/CoreGraphics.h"

class UIColor : public NSObject {
  public:
    static UIColor * blackColor();
    static UIColor * whiteColor();
    static UIColor * redColor();
    static UIColor * colorWithRedGreenBlueAlpha(CGFloat, CGFloat, CGFloat, CGFloat);

    COLORREF colorRef;

    UIColor();
};


// UICOLOR_H_
#endif