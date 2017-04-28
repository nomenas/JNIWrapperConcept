//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
#define JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H

#include "Converters.h"
#include "ClassInfo.h"
#include "Functional.h"

namespace jni_core {
    template<typename T>
    struct from<T*> {
        using Type = jobject;

        from<T*>(T *value, bool takeOwnership) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<T>::Class, constructor);
            set_reference(_value, value, takeOwnership);
        }

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<typename T>
    struct to<T*> {
        using Type = T*;

        to<T*>(jobject value) {
            _value = get_reference<T>(value);
        }

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<typename T>
    struct from_base_object {
        using Type = jobject;
        from_base_object<T>(T value) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<T>::Class, constructor);
            set_reference(_value, new T{value}, true);
        }
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct to_base_object {
        using Type = T;
        to_base_object<T>(jobject value) {
            _value = get_reference<T>(value);
        }
        const Type& value() const { return *_value; }
        operator const Type&() const { return *_value; }
        Type* _value = nullptr;
    };
}

#define USING_TO_OBJECT_CONVERTER(CLASS) \
template<> \
struct to<CLASS> : jni_core::to_base_object<CLASS> { \
    using jni_core::to_base_object<CLASS>::to_base_object; \
};

#define USING_FROM_OBJECT_CONVERTER(CLASS) \
template<> \
struct from<CLASS> : jni_core::from_base_object<CLASS> { \
    using jni_core::from_base_object<CLASS>::from_base_object; \
};

#endif //JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
