#include "SingleInheritance.h"


void SingleInheritance::method1() const {
    ++_counter;
}

int SingleInheritance::method2(int value) {
    return ++_counter + value;
}

int SingleInheritance::java_overridable() {
    return 0;
}

int SingleInheritanceExt::method2(int value) {
    return ++_counter + (value * 2);
}