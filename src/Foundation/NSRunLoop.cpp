#include "NSRunLoop.h"

NSRunLoop::NSRunLoop() {

}

void NSRunLoop::run() {
    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK NSRunLoop::WndProcedure( HWND hwnd,
                                          UINT msg,
                                          WPARAM wParam,
                                          LPARAM lParam ) {
    return 0;
}