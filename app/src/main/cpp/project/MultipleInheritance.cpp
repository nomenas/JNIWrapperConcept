#include "MultipleInheritance.h"

int BaseClass::baseClassMethod() {
    return 5;
}

ExtendAndImplement::ExtendAndImplement() : SimpleClass(12) {}

void ExtendAndImplement::method1() const {

}

int ExtendAndImplement::method2(int value) {
    return value + 10;
}

MultipleInheritance::MultipleInheritance() : SimpleClass(12) {}
