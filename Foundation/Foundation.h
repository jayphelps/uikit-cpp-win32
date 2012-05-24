#pragma once

#include <stdio.h>
#include <vector>

#define rgb(...) RGB(...)

typedef bool BOOL;

#define YES (BOOL)1
#define NO  (BOOL)0

typedef int NSInteger;
typedef unsigned int NSUInteger;

#define CGFLOAT_TYPE float
#define CGFLOAT_IS_DOUBLE 0
#define CGFLOAT_MIN FLT_MIN
#define CGFLOAT_MAX FLT_MAX

typedef CGFLOAT_TYPE CGFloat;

typedef struct {
   CGFloat x;
   CGFloat y;
} CGPoint;

typedef struct {
   CGFloat width;
   CGFloat height;
} CGSize;

typedef struct {
    CGPoint origin;
    CGSize size;
} CGRect;

#include "NSObject.h"