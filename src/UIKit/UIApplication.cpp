#include "UIApplication.h"

UIApplication::UIApplication() {

    // Register "class" with Win32
    this->_wndClassEx.style            = CS_HREDRAW | CS_VREDRAW;
    this->_wndClassEx.lpfnWndProc      = (WNDPROC) UIApplication::WndProcedure;
    this->_wndClassEx.cbClsExtra       = 0;
    this->_wndClassEx.cbWndExtra       = 0;
    this->_wndClassEx.hInstance        = UIApplication::_hInstance;
    this->_wndClassEx.hIcon            = NULL;
    this->_wndClassEx.hCursor          = 0;
    this->_wndClassEx.hbrBackground    = (HBRUSH) GetStockObject(HOLLOW_BRUSH);
    this->_wndClassEx.lpszMenuName     = 0;
    this->_wndClassEx.lpszClassName    = APP_NAME;
    this->_wndClassEx.cbSize           = sizeof(WNDCLASSEX);

    if ( !RegisterClassEx(&this->_wndClassEx) ) {
        // Handle that shit
        NSLog(L"RegisterClassEx FAILED: %d", GetLastError());
    }
}

UIApplication& UIApplication::sharedApplication() {
    static UIApplication instance;
    return instance;
}

LRESULT CALLBACK UIApplication::WndProcedure( HWND hWnd,
                                              UINT msg,
                                              WPARAM wParam,
                                              LPARAM lParam ) {

    LONG_PTR lpUserData = GetWindowLongPtr(hWnd, GWLP_USERDATA); 
    UIView* pView = (UIView *)lpUserData;

    if (pView) {

       
        //NSLog(pView->name);
    }

    switch (msg) {
        case WM_PAINT:
            if (pView && pView->needsDisplay) {

                HBRUSH hBrush,hTmpBr;
                PAINTSTRUCT ps;
                RECT rc;
                HDC hDC;

                hDC = BeginPaint(hWnd, &ps);

                    if (pView->backgroundColor) {
                        NSLog(L"NEEDED backgroundColor");
                        
                        hBrush = CreateSolidBrush(pView->backgroundColor->colorRef);
                        hTmpBr = (HBRUSH)SelectObject(hDC, hBrush);
                        GetClientRect(hWnd, &rc);
                        FillRect(hDC, &rc, hBrush);
                        DeleteObject(SelectObject(hDC, hTmpBr));
                    }

                EndPaint(hWnd, &ps);


                //pView->drawRect();
                break;
            }
        case WM_DESTROY:
            PostQuitMessage(WM_QUIT);
            break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}