//
// Created by Naum Puroski on 27/02/2017.
//

#ifndef WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
#define WRAPPERCONCEPT_MULTIPLEINHERITANCE_H

#include "SimpleClass.h"
#include "SimpleInterface.h"

class BaseClass {
public:
    int baseClassMethod();
};

class ExtendAndImplement : public SimpleClass, public SimpleInterface {
public:
    ExtendAndImplement();

    void method1() const;
    int method2(int value);
};

class MultipleInheritance : public SimpleClass, public BaseClass {
public:
    MultipleInheritance();
};

#endif //WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
