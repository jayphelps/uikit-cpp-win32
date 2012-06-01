#ifndef NSRUNLOOP_H_
#define NSRUNLOOP_H_
#pragma once

#include <windows.h>

#include "NSObject.h"

class NSRunLoop : public NSObject {
  public:
    NSRunLoop();

    void run();
};

// NSRUNLOOP_H_
#endif