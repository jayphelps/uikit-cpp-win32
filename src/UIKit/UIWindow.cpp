#include "UIWindow.h"
#include "UIColor.h"

UIWindow::UIWindow()
    : _rootViewController(NULL) {
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
    this->backgroundColor = UIColor::whiteColor();
    return this;
}

BOOL UIWindow::getIsKeyWindow() {
    //return (UIApplication::sharedApplication.keyWindow == this);
    return YES;
}

void UIWindow::_makeVisible() {
    this->isHidden = NO;
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