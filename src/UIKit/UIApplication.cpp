#include "UIApplication.h"
#include "UIColor.h"

UIApplication::UIApplication() {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Register "class" with Win32
    this->_wndClass.style            = CS_HREDRAW | CS_VREDRAW;
    this->_wndClass.lpfnWndProc      = (WNDPROC) UIApplication::WndProcedure;
    this->_wndClass.cbClsExtra       = 0;
    this->_wndClass.cbWndExtra       = 0;
    this->_wndClass.hInstance        = hInstance;
    this->_wndClass.hIcon            = NULL;
    this->_wndClass.hCursor          = 0;
    this->_wndClass.hbrBackground    = (HBRUSH) GetStockObject(HOLLOW_BRUSH);
    this->_wndClass.lpszMenuName     = 0;
    this->_wndClass.lpszClassName    = APP_NAME;
    //this->_wndClass.cbSize           = sizeof(this->_wndClass);

#ifdef _WIN32_WCE
    if ( !RegisterClass(&this->_wndClass) ) {
        NSLog(L"RegisterClass FAILED: %d", GetLastError());
    }
#else
    if ( !RegisterClassEx(&this->_wndClass) ) {
        NSLog(L"RegisterClassEx FAILED: %d", GetLastError());
    }
#endif

    /*WNDCLASSEX _wndClass2;

    // Register "class" with Win32
    _wndClass2.style            = CS_HREDRAW | CS_VREDRAW;
    _wndClass2.lpfnWndProc      = (WNDPROC) UIApplication::WndProcedure;
    _wndClass2.cbClsExtra       = 0;
    _wndClass2.cbWndExtra       = 0;
    _wndClass2.hInstance        = hInstance;
    _wndClass2.hIcon            = NULL;
    _wndClass2.hCursor          = 0;
    _wndClass2.hbrBackground    = (HBRUSH) GetStockObject(HOLLOW_BRUSH);
    _wndClass2.lpszMenuName     = 0;
    _wndClass2.lpszClassName    = L"Whoa dude";
    _wndClass2.cbSize           = sizeof(_wndClass2);

    if ( !RegisterClassEx(&_wndClass2) ) {
        // Handle that shit
        NSLog(L"RegisterClassEx FAILED: %d", GetLastError());
    }*/
}

UIApplication& UIApplication::sharedApplication() {
    static UIApplication instance;
    return instance;
}

LRESULT CALLBACK UIApplication::WndProcedure( HWND hWnd,
                                              UINT msg,
                                              WPARAM wParam,
                                              LPARAM lParam ) {

#ifdef _WIN32_WCE
    LONG lpUserData = GetWindowLong(hWnd, GWL_USERDATA);
#else
    LONG_PTR lpUserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
#endif

    CALayer* pLayer = (CALayer *)lpUserData;

    switch (msg) {
        case WM_PAINT:
            NSLog(L"WM_PAINT");

            if (pLayer) {
                NSLog(L"needsDisplay: %d", pLayer->needsDisplay);
            }
            if (pLayer /*&& pLayer->needsDisplay*/) {

                HBRUSH hBrush, hTmpBr;
                PAINTSTRUCT ps;
                
                HDC hDC;
                HWND hWndParent = GetParent(hWnd);

                /*CALayer *superlayer = pLayer->superlayer;
                if (superlayer) {
                    if (superlayer->_hWnd != hWndParent) {
                        NSLog(L"OH SHIT NO!! %d vs. %d", hWndParent, pLayer->_hWnd);
                    }
                }*/

                //InvalidateRect(hWnd, NULL, TRUE);

                hDC = BeginPaint(hWnd, &ps);

                    RECT rc;
                    if ( !GetClientRect(hWnd, &rc) ) {
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

                    if (pLayer->backgroundColor) {
                        NSLog(L"NEEDED backgroundColor");

                        hBrush = CreateSolidBrush(pLayer->backgroundColor->colorRef);
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

                EndPaint(hWnd, &ps);

                //ValidateRect(hWnd, NULL);
                //ReleaseDC(hWnd, hDC);
                //pLayer->drawRect(rect);

                pLayer->needsDisplay = NO;
                break;
            }

            return DefWindowProc(hWnd, msg, wParam, lParam);
        case WM_DESTROY:
            NSLog(L"WM_DESTROY");
            PostQuitMessage(WM_QUIT);
            break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}