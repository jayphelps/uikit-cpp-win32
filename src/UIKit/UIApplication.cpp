#include "UIApplication.h"
#include "UIColor.h"
#include "UIEvent.h"
#include "UIView.h"

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
        case WM_LBUTTONDOWN: {
            OutputDebugStringW(L"WM_LBUTTONDOWN\n");

            if (pLayer->delegate) {
                UIEvent event;
                event.x = GET_X_LPARAM(lParam);
                event.y = GET_Y_LPARAM(lParam);
                event.view = (UIView *) pLayer->delegate;

                pLayer->delegate->touchesBeganWithEvent(event);

            }

            /*if (view->userInteractionEnabled)
            {
                view->touchDown(view);
            }

            HWND hParent = GetParent(hwnd);

            if (hParent)
            {
                SendMessage(hParent, WM_LBUTTONDOWN, wParam, lParam);
            }*/

            break;
        }

        case WM_PAINT: {
            NSLog(L"WM_PAINT");

            if (pLayer) {
                NSLog(L"needsDisplay: %d", pLayer->needsDisplay);
            }
            if (pLayer /*&& pLayer->needsDisplay*/) {

                pLayer->display();
                pLayer->needsDisplay = NO;
                break;
            }

            return DefWindowProc(hWnd, msg, wParam, lParam);
        }

        case WM_DESTROY: {
            NSLog(L"WM_DESTROY");
            PostQuitMessage(WM_QUIT);
            break;
        }

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}