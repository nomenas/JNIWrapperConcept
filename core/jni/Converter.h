//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CONVERTERS_H
#define JNIWRAPPERCONCEPT_CONVERTERS_H

#include "../ConverterCore.h"

#include <jni.h>
#include <string>

namespace wrapper_core {
    DEFINE_CONVERTER(int, jint);
    DEFINE_CONVERTER(long, jlong);
    DEFINE_CONVERTER(bool, jboolean);
    DEFINE_CONVERTER(std::string, jstring);
}

#endif //JNIWRAPPERCONCEPT_CONVERTERS_H
