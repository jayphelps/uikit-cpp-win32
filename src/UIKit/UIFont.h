#ifndef UIFONT_H_
#define UIFONT_H_
#pragma once

#include "../Foundation/Foundation.h"
#include "../CoreGraphics/CoreGraphics.h"

class UIFont : public NSObject {
  public:
    static UIFont systemFontOfSize(CGFloat);
    CGFloat pointSize;
};

// UIFONT_H_
#endif