#include "UIApplication.h"
#include "UIColor.h"

UIApplication::UIApplication() {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Register "class" with Win32
    this->_wndClassEx.style            = CS_HREDRAW | CS_VREDRAW;
    this->_wndClassEx.lpfnWndProc      = (WNDPROC) UIApplication::WndProcedure;
    this->_wndClassEx.cbClsExtra       = 0;
    this->_wndClassEx.cbWndExtra       = 0;
    this->_wndClassEx.hInstance        = hInstance;
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
    CALayer* pLayer = (CALayer *)lpUserData;

    switch (msg) {
        case WM_PAINT:
            NSLog(L"WM_PAINT");

            if (pLayer) {
                NSLog(L"needsDisplay: %d", pLayer->needsDisplay);
            }
            if (pLayer && pLayer->needsDisplay) {

                HBRUSH hBrush, hTmpBr;
                PAINTSTRUCT ps;
                RECT rc;
                HDC hDC;

                hDC = BeginPaint(hWnd, &ps);
                    if (pLayer->backgroundColor) {
                        NSLog(L"NEEDED backgroundColor");

                        hBrush = CreateSolidBrush(pLayer->backgroundColor->colorRef);
                        hTmpBr = (HBRUSH)SelectObject(hDC, hBrush);
                        GetClientRect(hWnd, &rc);
                        FillRect(hDC, &rc, hBrush);
                        DeleteObject(SelectObject(hDC, hTmpBr));

                        CGRect rect = RectToCGRect(rc);

                        NSLog(L"POWER Width: %f", rect.size.width);
                    }

                EndPaint(hWnd, &ps);

                //
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