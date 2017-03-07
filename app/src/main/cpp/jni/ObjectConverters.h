//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
#define JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H

#include "Converters.h"
#include "ClassInfo.h"
#include "Functional.h"

template<typename T>
struct from<T*> {
    using Type = jobject;

    from<T*>(T* value, bool takeOwnership) {
        auto env = JNIEnvFactory::Create();
        jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
        _value = env->NewObject(ClassInfo<T>::Class, constructor);
        set_reference(_value, value, true);
    }
    Type value() const { return _value;}
    operator Type() const {return _value;}
    Type _value;
};

template<typename T>
struct to<T*> {
    using Type = T*;

    to<T*>(jobject value) {
        auto env = JNIEnvFactory::Create();
        _value = get_reference<T>(value);
    }
    Type value() const { return _value;}
    operator Type() const {return _value;}
    Type _value;
};

#endif //JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
