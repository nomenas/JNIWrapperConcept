//
// Created by Naum Puroski on 24/02/2017.
//

#include "SimpleClass.h"

#include <sstream>

SimpleClass::SimpleClass(int value) : _value(value){
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

Integer SimpleClass::get_object() const {
    return Integer(_value);
}

Integer* SimpleClass::get_owned_item() const {
    static Integer _instance(_value);
    return &_instance;
}

owner<Integer*> SimpleClass::get_item_take_ownership() const {
    return new Integer(_value);
}

int SimpleClass::call_method_with_ptr(Integer* obj, int value) const {
    return (obj ? obj->value() : 0) + value;
}

std::string SimpleClass::get_const_value() const {
    return "const value";
}

int SimpleClass::call_method_with_obj(Integer obj, int value) const {
    return obj.value() + value;
}

SimpleClass::Status SimpleClass::get_status() const {
    return Item2;
}

int SimpleClass::set_status(Status status) {
    return status;
}



