#ifndef UIAPPLICATION_H_
#define UIAPPLICATION_H_
#pragma once

#include "../Foundation/Foundation.h"

#include "UIApplicationDelegate.h"

class UIApplication : public NSObject {
  public:
    static UIApplication& UIApplication::sharedApplication();
    static LRESULT CALLBACK WndProcedure(HWND, UINT, WPARAM, LPARAM);

    UIApplicationDelegate *delegate;

  private:
    WNDCLASSEX _wndClassEx;
    HINSTANCE _hInstance;

    UIApplication();
    UIApplication(UIApplication const&);  // Don't Implement
    void operator=(UIApplication const&); // Don't implement
};

/**
 * This should probably be moved out of here...
 */
template<class TDelegate, class TApplication>
inline int UIApplicationMain( HINSTANCE hInstance,
                              HINSTANCE hPrevInstance,
                              wchar_t *pCmdLine,
                              int nCmdShow ) {

    UIApplication &application = TApplication::sharedApplication();
    application.delegate = new TDelegate();
    application.delegate->applicationDidFinishLaunching(application);

    NSRunLoop runLoop;
    runLoop.run();

    return 0;
}

// UIAPPLICATION_H_
#endif