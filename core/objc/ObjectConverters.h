//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
#define JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H

#include "Converters.h"
#include "Functional.h"

namespace wrapper_core {
    template<typename T, typename >
    struct from_base_object {
        using Type = void*;
//        from_base_object<T>(T value) {
//            auto env = JNIEnvFactory::Create();
//            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
//            _value = env->NewObject(ClassInfo<T>::Class, constructor);
//            set_reference(_value, new T{value}, true);
//        }
//        Type value() const { return _value; }
//        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct to_base_object {
        using Type = void*;
//        to_base_object<T>(jobject value) {
//            _value = get_reference<T>(value);
//        }
//        const Type& value() const { return *_value; }
//        operator const Type&() const { return *_value; }
        Type _value = nullptr;
    };
}

#endif //JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
