#include "UIFont.h"

UIFont UIFont::systemFontOfSize(CGFloat size) {
    UIFont font;
    font.pointSize = size;
    return font;
}