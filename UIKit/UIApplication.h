#pragma once

#include <Foundation/Foundation.h>

#include "UIApplicationDelegate.h"

class UIApplication : public NSObject {
  public:
    UIApplicationDelegate *delegate;

    static UIApplication& sharedApplication() {
        static UIApplication instance;
        return instance;
    }

  private:
    UIApplication();
    UIApplication(UIApplication const&);  // Don't Implement
    void operator=(UIApplication const&); // Don't implement
};

/**
 * This should probably be moved out of here...
 */
template<class TDelegate, class TApplication>
inline int UIApplicationMain() {
    UIApplication &application = TApplication::sharedApplication();
    application.delegate = new TDelegate;
    application.delegate->applicationDidFinishLaunching(application);

    return 0;
}