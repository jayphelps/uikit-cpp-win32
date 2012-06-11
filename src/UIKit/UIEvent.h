#ifndef UIEVENT_H_
#define UIEVENT_H_
#pragma once

#include "../Foundation/Foundation.h"

class UIView;

class UIEvent : public NSObject {
  public:
    NSInteger x;
    NSInteger y;
    UIView *view;

    UIEvent();
    virtual ~UIEvent();
};

// UIEVENT_H_
#endif