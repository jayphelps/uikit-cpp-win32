#include "UIView.h"

UIView::UIView() {
    this->needsDisplay = YES;
}

UIView::~UIView() {

}

UIView * UIView::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);

    return this;
}

UIView * UIView::_initWithFrame(CGRect frame) {
    this->frame = frame;

    
    /*this->_hWnd = CreateWindow( this->lpClassName,
                               this->title,
                               this->dwStyle,
                               x, y, w, h,
                               NULL,
                               NULL,
                               this->_hInstance,
                               NULL );*/
    return this;
}

void UIView::addSubview(UIView *subview) {
    this->needsDisplay = YES;
    this->subviews.push_back(subview);
}

void UIView::drawRect(CGRect rect) {

}