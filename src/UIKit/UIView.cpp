#include "UIView.h"
#include "../QuartzCore/CALayer.h"

UIView::UIView()
    : layer(NULL)
    , _viewController(NULL)
    , superview(NULL) {
}

UIView::~UIView() {
    delete this->layer;
}

UIView * UIView::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);

    return this;
}

UIView * UIView::_initWithFrame(CGRect frame) {
    // Create and set up our layer first
    this->layer = (new CALayer)->initWithFrame(frame);
    this->layer->delegate = this;

    // Now do our internal work
    this->frame = frame;
    this->needsDisplay = YES;

    return this;
}

void UIView::addSubview(UIView *subview) {
    //this->_subviews addObject:subview];
    //_subviewControllersNeedAppearAndDisappear
    subview->superview = this;
    this->layer->addSublayer(subview->layer);
}

void UIView::drawLayerInContext(CALayer *layer, CGContextRef contextRef) {

}

void UIView::drawRect(CGRect rect) {
    /*PAINTSTRUCT Ps;
    RECT rc;
    BOOL result = YES;

    HDC hDC;
    HDC hdcMem;
    HBITMAP bitmap;

    GetClientRect(this->_hWnd, &rc);
    
    InvalidateRect(this->_hWnd, NULL, TRUE);

    hDC = GetDC(this->_hWnd);

    if (this->needsDisplay || TRUE) {
        this->needsDisplay = NO;

        hdcMem = CreateCompatibleDC(hDC);

        bitmap = CreateCompatibleBitmap( hDC,
                                               rc.right-rc.left,
                                               rc.bottom-rc.top );

        SelectObject(hdcMem, bitmap);
    
    }

    BitBlt(hDC,
           0,0,
           rc.right-rc.left,
           rc.bottom-rc.top,
           hdcMem,
           0,0,
           SRCCOPY);

    ValidateRect(this->_hWnd, NULL);

    //ReleaseDC(this->_hWnd, this->hDC);
    //DeleteDC(this->hdcMem);
    //DeleteObject(this->bitmap);

*/
}

BOOL UIView::getHidden() {
    return this->layer->isHidden;
}

void UIView::setHidden(BOOL value) {
    this->layer->isHidden = value;
}

BOOL UIView::getNeedsDisplay() {
    return this->layer->needsDisplay;
}

void UIView::setNeedsDisplay(BOOL value) {
    this->layer->needsDisplay = value;
}

CGRect UIView::getFrame() {
    return this->layer->frame;
}

void UIView::setFrame(CGRect newFrame) {
    if (this->layer) {
        this->layer->frame = newFrame;
    }
}

UIColor * UIView::getBackgroundColor() {
    return this->layer->backgroundColor;
}

void UIView::setBackgroundColor(UIColor *color) {
    this->layer->backgroundColor = color;
}