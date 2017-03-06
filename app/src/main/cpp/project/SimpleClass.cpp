//
// Created by Naum Puroski on 24/02/2017.
//

#include "SimpleClass.h"

#include <sstream>

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
    return nullptr;
}

owner<SimpleClass*> SimpleClass::get_item_take_ownership() const {
    return nullptr;
}