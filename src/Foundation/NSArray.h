#ifndef NSARRAY_H_
#define NSARRAY_H_
#pragma once

#include "../Foundation/Foundation.h"
//#include "Foundation/NSEnumerator.h"
//#include "Foundation/NSRange.h"
//#include "Foundation/NSObjCRuntime.h"

class NSArray : public NSObject {
  public:
    NSUInteger count;

    NSArray * initWithObject(NSObject *);
};

// NSARRAY_H_
#endif