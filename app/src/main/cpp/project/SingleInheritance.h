//
// Created by Naum Puroski on 13/04/2017.
//

#ifndef JNIWRAPPERCONCEPT_SINGLEINHERITANCE_H
#define JNIWRAPPERCONCEPT_SINGLEINHERITANCE_H

#include "SimpleInterface.h"

class SingleInheritance : public SimpleInterface {
public:
    void method1() const override {
        ++_counter;
    }

    int method2(int value) override {
        return ++_counter + value;
    }

protected:
    mutable int _counter = 0;
};

class SingleInheritanceExt : public SingleInheritance {
public:
    int method2(int value) override {
        return ++_counter + (value * 2);
    }
};

#endif //JNIWRAPPERCONCEPT_SINGLEINHERITANCE_H
