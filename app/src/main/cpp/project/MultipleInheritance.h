//
// Created by Naum Puroski on 27/02/2017.
//

#ifndef WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
#define WRAPPERCONCEPT_MULTIPLEINHERITANCE_H

#include "SimpleClass.h"
#include "SimpleInterface.h"

class BaseClass {
public:
    int baseClassMethod() {
        return 5;
    }
};

class ExtendAndImplement : public SimpleClass, public SimpleInterface {
public:
    ExtendAndImplement() : SimpleClass(12) {}

    void method1() const {

    }

    int method2(int value) {
        return value + 10;
    }
};

class MultipleInheritance : public SimpleClass, public BaseClass {
public:
    MultipleInheritance() : SimpleClass(12) {}
};

#endif //WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
