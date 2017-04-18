#include "SingleInheritance.h"


void SingleInheritance::method1() const {
    ++_counter;
}

int SingleInheritance::method2(int value) {
    return ++_counter + value;
}

int SingleInheritanceExt::method2(int value) {
    return ++_counter + (value * 2);
}