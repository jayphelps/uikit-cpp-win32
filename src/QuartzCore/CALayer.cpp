#include "CALayer.h"
// @FIXME This is BAD BAD BAD!!
#include "../UIKit/UIColor.h"

CALayer::CALayer()
    : superlayer(NULL)
    , delegate(NULL)
    , _dwStyle(WS_DISABLED)
    , _hWnd(NULL)
    , backgroundColor(NULL) {
}

CALayer::~CALayer() {

}

CALayer * CALayer::init() {
    return this->initWithFrame(CGRectZero);
}

CALayer * CALayer::initWithFrame(CGRect frame) {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    NSLog(L"FIRST width: %d", (int)frame.size.width);
    NSLog(L"FIRST height: %d", (int)frame.size.height);

    static int doIt = 0;

    this->_hWnd = CreateWindow( APP_NAME,                // lpClassName
                                NULL,                    // lpWindowName
                                doIt > 0 ? this->_dwStyle : NULL,          // dwStyle
                                (int) frame.origin.x,    // x
                                (int) frame.origin.y,    // y
                                (int) frame.size.width,  // width
                                (int) frame.size.height, // height
                                NULL,                    // hWndParent
                                NULL,                    // hMenu
                                hInstance,               // hInstance
                                NULL );                  // lpParam

    
    doIt++;

    if ( !this->_hWnd ) {
        NSLog(L"CreateWindow FAILED: %d", GetLastError());
    }

#ifdef _WIN32_WCE
    SetWindowLong(this->_hWnd, GWL_USERDATA, (LONG)this);
#else
    // Some Win64 SDKs cause warnings with normal cast to LONG_PTR
    // http://forums.codeguru.com/showthread.php?t=432705
    SetWindowLongPtr(this->_hWnd, GWLP_USERDATA, (__int3264)(LONG_PTR)this);
#endif

    //this->isHidden = NO;

    //UpdateWindow(this->_hWnd);

    return this;
}

CALayer * CALayer::initWithLayer(CALayer *layer) {
    return layer;
}

void CALayer::addSublayer(CALayer *sublayer) {

    if ( !SetParent(sublayer->_hWnd, this->_hWnd) ) {
        NSLog(L"SetParent FAILED: %d", GetLastError());
    }

    SetWindowLong(sublayer->_hWnd, GWL_STYLE, WS_VISIBLE|WS_CHILD|WS_POPUP );
    
    if ( !ShowWindow(sublayer->_hWnd, SW_SHOW) ) {
        NSLog(L"ShowWindow FAILED: %d", GetLastError());
    }

    sublayer->superlayer = this;
    sublayer->needsDisplay = YES;

    /*if ( !BringWindowToTop(sublayer->_hWnd) ) {
        NSLog(L"BringWindowToTop FAILED: %d", GetLastError());
    }*/

    UpdateWindow(this->_hWnd);
}

void CALayer::removeSublayer(CALayer *sublayer) {
    if ( !SetParent(sublayer->_hWnd, NULL) ) {
        NSLog(L"SetParent FAILED: %d", GetLastError());
    }

    SetWindowLong(sublayer->_hWnd, GWL_STYLE, NULL );
    
    if ( !ShowWindow(sublayer->_hWnd, SW_HIDE) ) {
        NSLog(L"ShowWindow FAILED: %d", GetLastError());
    }

    sublayer->superlayer = NULL;
    //sublayer->needsDisplay = NO;

    /*if ( !BringWindowToTop(sublayer->_hWnd) ) {
        NSLog(L"BringWindowToTop FAILED: %d", GetLastError());
    }*/

    UpdateWindow(this->_hWnd);
}

void CALayer::display() {
    if (this->delegate) {
        //this->displayLayer(this);
    }
    CGContextRef context;

    this->drawInContext(context);
}

void CALayer::drawInContext(CGContextRef contextRef) {
    HBRUSH hBrush, hTmpBr;
    PAINTSTRUCT ps;
    
    HDC hDC;
    HWND hWndParent = GetParent(this->_hWnd);

    /*CALayer *superlayer = pLayer->superlayer;
    if (superlayer) {
        if (superlayer->_hWnd != hWndParent) {
            NSLog(L"OH SHIT NO!! %d vs. %d", hWndParent, pLayer->_hWnd);
        }
    }*/

    //InvalidateRect(hWnd, NULL, TRUE);

    hDC = BeginPaint(this->_hWnd, &ps);

        RECT rc;
        if ( !GetClientRect(this->_hWnd, &rc) ) {
            NSLog(L"GetClientRect failed: %d", GetLastError());
        }

        //MapWindowRect(hWnd, hWndParent, &rc);

        /*CGRect rect = pLayer->frame;
        RECT rc = CGRectToWin32Rect(rect);
        CGRect pooRect = Win32RectToCGRect(rc);

        if (!CGRectEqualToRect(rect, pooRect)) {
            NSLog(L"\n\n");
            NSLog(L"%f", rect.size.height);
            NSLog(L"%f", pooRect.size.height);
            NSLog(L"%d %d", rc.bottom, rc.top);
        }*/

        if (this->backgroundColor) {
            NSLog(L"NEEDED backgroundColor");

            hBrush = CreateSolidBrush(this->backgroundColor->colorRef);
            hTmpBr = (HBRUSH)SelectObject(hDC, hBrush);

            FillRect(hDC, &rc, hBrush);
            DeleteObject(SelectObject(hDC, hTmpBr));


            //NSLog(L"POWER width: %d | %f", rc.right - rc.left, rect.size.width);
            //NSLog(L"POWER height: %d | %f", rc.bottom - rc.top, rect.size.height);
            NSLog(L"left: %d", rc.left);
            NSLog(L"top: %d", rc.top);
            NSLog(L"right: %d", rc.right);
            NSLog(L"bottom: %d", rc.bottom);
        }

    EndPaint(this->_hWnd, &ps);

    if (this->delegate) {
        this->delegate->drawLayerInContext(this, contextRef);
        return;
    }
}

BOOL CALayer::getNeedsDisplay() {
    return this->_needsDisplay;
}

void CALayer::setNeedsDisplay(BOOL value) {
    this->_needsDisplay = value;
    UpdateWindow(this->_hWnd);
}

BOOL CALayer::getHidden() {
    return NO;
}

void CALayer::setHidden(BOOL shouldHide) {
    int bitmask = shouldHide ? SW_HIDE : SW_SHOW;

   if ( !ShowWindow(this->_hWnd, bitmask) ) {
        NSLog(L"ShowWindow FAILED: %d", GetLastError());
    }

    /*if ( !BringWindowToTop(this->_hWnd) ) {
        NSLog(L"BringWindowToTop FAILED: %d", GetLastError());
    }*/

    if ( !EnableWindow(this->_hWnd, !shouldHide) ) {
        NSLog(L"EnableWindow FAILED: %d", GetLastError());
    }

    UpdateWindow(this->_hWnd);
}