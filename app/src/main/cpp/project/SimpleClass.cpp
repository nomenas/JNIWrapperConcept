//
// Created by Naum Puroski on 24/02/2017.
//

#include "SimpleClass.h"

#include <sstream>

SimpleClass::SimpleClass(int) {

}

void SimpleClass::method1() const {
}

int SimpleClass::method2(int value) {
    return value;
}

std::string SimpleClass::method3(int value, const std::string& text) {
    std::stringstream ss;
    ss << text << " " << value;
    return ss.str();
}

SimpleClass* SimpleClass::get_owned_item() const {
    static SimpleClass _instance(0);
    return &_instance;
}

owner<SimpleClass*> SimpleClass::get_item_take_ownership() const {
    return new SimpleClass(0);
}

int SimpleClass::callMethod(SimpleClass* obj, int value) const {
    return obj ? obj->method2(value) : 0;
}



