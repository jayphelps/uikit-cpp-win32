#include "UIViewController.h"

UIViewController::UIViewController() {
    this->view.setContainer(this);
    this->view.setter(&UIViewController::setView);
    this->view.getter(&UIViewController::getView);
}

UIViewController::~UIViewController() {

}

void UIViewController::loadView() {
    CGRect frame = CGRectMake(0, 0, 100, 200);

    // Create an empty view by default
    this->view = (new UIView)->initWithFrame(frame);
}

void UIViewController::viewDidLoad() {
    
}