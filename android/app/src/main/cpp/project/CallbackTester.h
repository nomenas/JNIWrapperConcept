//
// Created by Naum Puroski on 24/02/2017.
//

#ifndef WRAPPERCONCEPT_CONCRETECLASS_H
#define WRAPPERCONCEPT_CONCRETECLASS_H

#include "Callback.h"
#include <functional>

class CallbackTester {
public:
    CallbackTester(int value);

    void do_callback(Callback* callback);
    void do_callback(std::function<void(int)> callback);

private:
    int _value;
};


#endif //WRAPPERCONCEPT_CONCRETECLASS_H
