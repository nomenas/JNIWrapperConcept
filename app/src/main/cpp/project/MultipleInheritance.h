//
// Created by Naum Puroski on 27/02/2017.
//

#ifndef WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
#define WRAPPERCONCEPT_MULTIPLEINHERITANCE_H

#include "SimpleClass.h"

class SimpleInterface {
public:

    virtual ~SimpleInterface() = default;

    virtual void method1() const = 0;
    virtual int method2(int value) = 0;
};

class BaseClass {};

class SingleInheritance : public SimpleInterface {
public:
    void method() const {

    }

    int method2(int value) {
        return value + 5;
    }
};

class MultipleInheritance : public BaseClass, public SimpleInterface {
public:
    void method() const {

    }

    int method2(int value) {
        return value + 10;
    }
};

#endif //WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
