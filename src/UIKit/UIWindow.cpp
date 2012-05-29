#include "UIWindow.h"

UIWindow::UIWindow() : _rootViewController(NULL) {
    this->rootViewController.setContainer(this);
    this->rootViewController.setter(&UIWindow::setRootViewController);
    this->rootViewController.getter(&UIWindow::getRootViewController);
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

void UIWindow::makeKeyAndVisible() {

}