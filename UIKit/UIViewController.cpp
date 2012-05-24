#include "UIViewController.h"

UIViewController::UIViewController() {

}

UIViewController::~UIViewController() {

}

void UIViewController::loadView() {
    CGRect frame;

    // Create an empty view by default
    this->view = (new UIView)->initWithFrame(frame);
}

void UIViewController::viewDidLoad() {
    
}