//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CONVERTERS_H
#define JNIWRAPPERCONCEPT_CONVERTERS_H

#include "JNIEnvFactory.h"

namespace jni_core {
    template<typename T>
    struct from {
    };

    template<typename T>
    struct to {
    };

    template<typename From, typename To>
    struct to_base {
        using Type = To;

        to_base<From, To>(From value) : _value(value) {}

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<typename From, typename To>
    struct from_base {
        using Type = To;

        from_base<From, To>(Type value) : _value(value) {}

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<>
    struct to<int> : to_base<jint, int> {
        using to_base<jint, int>::to_base;
    };
    template<>
    struct from<int> : from_base<int, jint> {
        using from_base<int, jint>::from_base;
    };

    template<>
    struct to<long> : to_base<jlong, long> {
        using to_base<jlong, long>::to_base;
    };
    template<>
    struct from<long> : from_base<long, jlong> {
        using from_base<long, jlong>::from_base;
    };

    template<>
    struct to<bool> : to_base<jboolean, bool> {
        using to_base<jboolean, bool>::to_base;
    };
    template<>
    struct from<bool> : from_base<bool, jboolean> {
        using from_base<bool, jboolean>::from_base;
    };

    template<>
    struct to<void *> {
        using Type = void *; \


        to<Type>(jlong value) : _value(reinterpret_cast<void *>(value)) {} \


        Type value() const { return _value; } \


        operator Type() const { return _value; } \


        Type _value;
    };

    template<>
    struct from<void *> {
        using Type = jlong;

        template<typename T>
        from<long>(T *ptr) : _value(reinterpret_cast<long>(ptr)) {};

        Type value() const { return _value; }

        Type _value;
    };

    template<>
    struct to<std::string> {
        using Type = std::string;

        to<Type>(jstring value) {
            auto env = JNIEnvFactory::Create();
            if (env) {
                const char *text = env->GetStringUTFChars(value, 0);
                _value = text;
                env->ReleaseStringUTFChars(value, text);
            }
        }

        Type value() const {
            return _value;
        }

        operator Type() const { return _value; }

        Type _value;
    };

    template<>
    struct from<std::string> {
        using Type = jstring;

        from<std::string>(const std::string &value) : _value(nullptr) {
            auto env = JNIEnvFactory::Create();
            if (env) {
                _value = env->NewStringUTF(value.c_str());
            }
        }

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };
}

#endif //JNIWRAPPERCONCEPT_CONVERTERS_H
