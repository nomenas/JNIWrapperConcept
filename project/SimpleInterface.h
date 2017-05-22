//
// Created by Naum Puroski on 13/04/2017.
//

#ifndef JNIWRAPPERCONCEPT_SIMPLEINTERFACE_H
#define JNIWRAPPERCONCEPT_SIMPLEINTERFACE_H

class SimpleInterface {
public:

    virtual ~SimpleInterface() = default;

    virtual void method1() const = 0;
    virtual int method2(int value) = 0;
    virtual int java_overridable() = 0;
};

#endif //JNIWRAPPERCONCEPT_SIMPLEINTERFACE_H
