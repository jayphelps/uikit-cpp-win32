#include "UIWindow.h"

UIWindow::UIWindow()
    : _rootViewController(NULL) {
    this->backgroundColor = UIColor::whiteColor();
}

UIViewController * UIWindow::getRootViewController() {
    return this->_rootViewController;
}

void UIWindow::setRootViewController(UIViewController *controller) {
    this->addSubview(controller->view);
    this->_rootViewController = controller;
}

UIWindow * UIWindow::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);

    return this;
}

BOOL UIWindow::getIsKeyWindow() {
    //return (UIApplication::sharedApplication.keyWindow == this);
    return YES;
}

void UIWindow::_makeVisible() {
    if ( !ShowWindow(this->_hWnd, SW_SHOW) ) {
        NSLog(L"ShowWindow FAILED: %d", GetLastError());
    }

    if ( !BringWindowToTop(this->_hWnd) ) {
        NSLog(L"BringWindowToTop FAILED: %d", GetLastError());
    }

    if ( !EnableWindow(this->_hWnd, YES) ) {
        NSLog(L"EnableWindow FAILED: %d", GetLastError());
    }
}

void UIWindow::makeKeyWindow() {
    //if (!this.isKeyWindow) {
        //[[UIApplication sharedApplication].keyWindow resignKeyWindow];
        //UIApplication->sharedApplication().setKeyWindow(this);
        //this->becomeKeyWindow();
    //}
}

void UIWindow::makeKeyAndVisible() {
    this->_makeVisible();
    this->makeKeyWindow();
}