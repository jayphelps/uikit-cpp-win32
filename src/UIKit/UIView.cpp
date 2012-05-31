#include "UIView.h"

UIView::UIView()
    : backgroundColor(NULL)
    , needsDisplay(YES)
    , dwStyle(WS_DISABLED)
    , _hWnd(NULL) {
}

UIView::~UIView() {

}

UIView * UIView::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);

    return this;
}

UIView * UIView::_initWithFrame(CGRect frame) {
    this->frame = frame;

    this->_hWnd = CreateWindow( APP_NAME,       // lpClassName
                                NULL,           // lpWindowName
                                this->dwStyle,           // dwStyle
                                frame.origin.x,
                                frame.origin.y,
                                frame.size.width,
                                frame.size.height, // x, y, width, height
                                NULL,           // hWndParent
                                NULL,           // hMenu
                                NULL,     // hInstance
                                NULL );         // lpParam

    
    if ( !this->_hWnd ) {
        NSLog(L"CreateWindow FAILED: %d", GetLastError());
    }

    SetWindowLongPtr(this->_hWnd, GWLP_USERDATA, (LONG_PTR)this);

    return this;
}

void UIView::addSubview(UIView *subview) {
    this->needsDisplay = YES;
    subview->needsDisplay = YES;

    //this->subviews.push_back(subview);

    if ( !SetParent(subview->_hWnd, this->_hWnd) ) {
        NSLog(L"SetParent FAILED: %d", GetLastError());
    }

    SetWindowLong(subview->_hWnd, GWL_STYLE, WS_VISIBLE|WS_CHILD);

    if ( !ShowWindow(subview->_hWnd, SW_SHOW) ) {
        NSLog(L"ShowWindow FAILED: %d", GetLastError());
    }

    if ( !BringWindowToTop(subview->_hWnd) ) {
        NSLog(L"BringWindowToTop FAILED: %d", GetLastError());
    }

    if ( !EnableWindow(subview->_hWnd, YES) ) {
        NSLog(L"EnableWindow FAILED: %d", GetLastError());
    }
}

BOOL UIView::drawRect(CGRect rect) {
    PAINTSTRUCT Ps;
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

    return result;
}