//
// Created by Naum Puroski on 13/04/2017.
//

#ifndef JNIWRAPPERCONCEPT_SINGLEINHERITANCE_H
#define JNIWRAPPERCONCEPT_SINGLEINHERITANCE_H

#include "SimpleInterface.h"

class SingleInheritance : public SimpleInterface {
public:
    void method1() const override;
    int method2(int value) override;

    int java_overridable() override;

protected:
    mutable int _counter = 0;
};

class SingleInheritanceExt : public SingleInheritance {
public:
    int method2(int value) override;
};

#endif //JNIWRAPPERCONCEPT_SINGLEINHERITANCE_H
