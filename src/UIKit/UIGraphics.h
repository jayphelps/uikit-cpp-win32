#include "../Foundation/Foundation.h"
#include "../CoreGraphics/CoreGraphics.h"

#include "UIKitDefines.h"

UIKIT_EXTERN CGContextRef UIGraphicsGetCurrentContext();

UIKIT_EXTERN void UIGraphicsPushContext(CGContextRef);

UIKIT_EXTERN void UIGraphicsPopContext();

UIKIT_EXTERN void CGContextSaveGState(CGContextRef);

UIKIT_EXTERN void CGContextRestoreGState(CGContextRef);

UIKIT_EXTERN void UIGraphicsBeginImageContext(CGSize);

UIKIT_EXTERN void UIRectFill(CGRect rect);