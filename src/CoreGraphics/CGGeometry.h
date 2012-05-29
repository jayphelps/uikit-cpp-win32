#ifndef CGGEOMETRY_H_
#define CGGEOMETRY_H_
#pragma once

#include "CoreGraphics/CGBase.h"

/**
 * Points
 */
typedef struct {
    CGFloat x;
    CGFloat y;
} CGPoint;

/**
 * Sizes
 */
typedef struct {
    CGFloat width;
    CGFloat height;
} CGSize;

/**
 * Rectangles
 */
typedef struct {
    CGPoint origin;
    CGSize size;
} CGRect;

/**
 * Rectangle edges
 */
typedef enum {
    CGRectMinXEdge,
    CGRectMinYEdge,
    CGRectMaxXEdge,
    CGRectMaxYEdge
} CGRectEdge;

/**
 * CGPoint helper from (x, y)
 */
CG_INLINE CGPoint CGPointMake( CGFloat x, CGFloat y ) {
    CGPoint p; p.x = x; p.y = y; return p;
}

/**
 * CGSize helper from (width, height)
 */
CG_INLINE CGSize CGSizeMake( CGFloat width, CGFloat height ) {
    CGSize size;
    size.width = width;
    size.height = height;
    return size;
}

/**
 * CGRect helper from (x, y, width, height)
 */
CG_INLINE CGRect CGRectMake( CGFloat x,
                             CGFloat y,
                             CGFloat width,
                             CGFloat height ) {
    CGRect rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = width;
    rect.size.height = height;
    return rect;
}

/**
 * Compare to CGPoints if equal
 */
CG_INLINE bool CGPointEqualToPoint( CGPoint point1, CGPoint point2 ) {
    return point1.x == point2.x && point1.y == point2.y;
}

/**
 * Compare two CGSizes if equal
 */
CG_INLINE bool CGSizeEqualToSize( CGSize size1, CGSize size2 ) {
    return size1.width == size2.width && size1.height == size2.height;
}

// CGGEOMETRY_H_
#endif