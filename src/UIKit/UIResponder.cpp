#include "UIResponder.h"
#include "UIEvent.h"

UIResponder::UIResponder() {
    
}

UIResponder::~UIResponder() {
    
}

void UIResponder::touchesBeganWithEvent(UIEvent event) {
    if (this->nextResponder) {
        this->nextResponder->touchesBeganWithEvent(event);
    }

    /*if (this->_action) {
        //this->_action(this);
        //(this->_target->*this->_action)(this);

    }*/
}

void UIResponder::addTarget(UIViewController *target, FuncType action, UIControlEvents controlEvents) {
    this->_target = target;
    this->_action = action;
}

void UIResponder::drawLayerInContext(CALayer *layer, CGContextRef context) {

}

UIResponder * UIResponder::getNextResponder() {
    return NULL;
}

void UIResponder::setNextResponder(UIResponder *) {

}