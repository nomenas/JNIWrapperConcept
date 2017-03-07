//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CLASSINFO_H
#define JNIWRAPPERCONCEPT_CLASSINFO_H

#include <string>

template <typename T>
struct ClassInfo {
    static const char* Name;
    static jclass Class;
};

#endif //JNIWRAPPERCONCEPT_CLASSINFO_H
