#include "UIApplication.h"

UIApplication::UIApplication() {
    // Register "class" with Win32
    this->_wndClassEx.style            = CS_HREDRAW | CS_VREDRAW;
    this->_wndClassEx.lpfnWndProc      = (WNDPROC) NSRunLoop::WndProcedure;
    this->_wndClassEx.cbClsExtra       = 0;
    this->_wndClassEx.cbWndExtra       = 0;
    this->_wndClassEx.hInstance        = UIApplication::_hInstance;
    this->_wndClassEx.hIcon            = NULL;
    this->_wndClassEx.hCursor          = 0;
    this->_wndClassEx.hbrBackground    = (HBRUSH) GetStockObject(HOLLOW_BRUSH); // WHITE_BRUSH
    this->_wndClassEx.lpszMenuName     = 0;
    this->_wndClassEx.lpszClassName    = APP_NAME;

    if (!RegisterClassEx(&this->_wndClassEx)) {
        // Handle that shit
    }
}