#include "UIWindow.h"

UIWindow::UIWindow() {
    this->rootViewController.setContainer(this);
    this->rootViewController.setter(&UIWindow::setRootViewController);
    this->rootViewController.getter(&UIWindow::getRootViewController);
}

UIWindow * UIWindow::initWithFrame(CGRect frame) {
    this->_initWithFrame(frame);

    return this;
}

void UIWindow::makeKeyAndVisible() {

}