#include "UIColor.h"

UIColor::UIColor() {

}

UIColor * UIColor::blackColor() {
    return UIColor::colorWithRedGreenBlueAlpha(0.0f, 0.0f, 0.0f, 1.0f);
}

UIColor * UIColor::whiteColor() {
    return UIColor::colorWithRedGreenBlueAlpha(255.0f, 255.0f, 255.0f, 1.0f);
}

UIColor * UIColor::redColor() {
    return UIColor::colorWithRedGreenBlueAlpha(255.0f, 0.0f, 0.0f, 0.0f);
}

UIColor * UIColor::greenColor() {
    return UIColor::colorWithRedGreenBlueAlpha(0.0f, 255.0f, 0.0f, 0.0f);
}

UIColor * UIColor::yellowColor() {
    return UIColor::colorWithRedGreenBlueAlpha(255.0f, 255.0f, 0.0f, 0.0f);
}

UIColor * UIColor::magentaColor() {
    return UIColor::colorWithRedGreenBlueAlpha(255.0f, 0.0f, 255.0f, 0.0f);
}

UIColor * UIColor::colorWithRedGreenBlueAlpha( CGFloat red,
                                               CGFloat green,
                                               CGFloat blue,
                                               CGFloat alpha ) {
    UIColor *color = new UIColor();
    
    color->colorRef = RGB(red, green, blue);

    return color;
}