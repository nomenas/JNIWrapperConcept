//
// Created by Naum Puroski on 24/02/2017.
//

#include <cwchar>
#include "CallbackTester.h"
#include "SimpleClass.h"

CallbackTester::CallbackTester(int value) : _value(value){

}

void CallbackTester::do_callback(Callback* callback) {
    if (callback) {
        callback->something_happened(_value);
    }
}
void CallbackTester::do_callback(std::function<void(int)> callback) {
    callback(_value);
}

