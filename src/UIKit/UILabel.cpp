#include "UILabel.h"
#include "UIColor.h"

UILabel::UILabel() {
}

UILabel::~UILabel() {
    
}

UILabel * UILabel::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);
    this->backgroundColor = UIColor::whiteColor();
    return this;
}

void UILabel::drawRect(CGRect rect) {
    /*
    CGContextSaveGState(UIGraphicsGetCurrentContext());
    CGContextSetShadowWithColor(UIGraphicsGetCurrentContext(), offset, 0, _shadowColor.CGColor);
    
    // finally, draw the real label
    UIColor *drawColor = (_highlighted && _highlightedTextColor)? _highlightedTextColor : _textColor;
    [drawColor setFill];
    [self drawTextInRect:drawRect];
    
    CGContextRestoreGState(UIGraphicsGetCurrentContext());
    */
}

std::wstring UILabel::getText() {
    return this->_text;
}

void UILabel::setText(std::wstring value) {
    this->_text = value;
    this->needsDisplay = YES;
}

UIColor * UILabel::getTextColor() {
    return this->_textColor;
}

void UILabel::setTextColor(UIColor *value) {
    this->_textColor = value;
    this->needsDisplay = YES;
}

UIColor * UILabel::getShadowColor() {
    return this->_shadowColor;
}

void UILabel::setShadowColor(UIColor *value) {
    this->_shadowColor = value;
    this->needsDisplay = YES;
}

CGSize UILabel::getShadowOffset() {
    return this->_shadowOffset;
}

void UILabel::setShadowOffset(CGSize value) {
    this->_shadowOffset = value;
    this->needsDisplay = YES;
}