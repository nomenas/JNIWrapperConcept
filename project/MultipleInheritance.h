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

    void method1() const override;
    int method2(int value) override;

    int java_overridable() override;
};

class MultipleInheritance : public SimpleClass, public BaseClass {
public:
    MultipleInheritance();
};

#endif //WRAPPERCONCEPT_MULTIPLEINHERITANCE_H
