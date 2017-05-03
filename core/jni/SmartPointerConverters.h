//
// Created by Naum Puroski on 18/04/2017.
//

#ifndef JNIWRAPPERCONCEPT_SMARTPOINTERCONVERTERS_H
#define JNIWRAPPERCONCEPT_SMARTPOINTERCONVERTERS_H

#include "Converter.h"
#include "ClassInfo.h"
#include "Functional.h"

namespace wrapper_core {
    template<typename T>
    struct from<std::shared_ptr<T>> {
        using Type = jobject;

        from<std::shared_ptr<T>>(std::shared_ptr<T> value) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<T>::Class, constructor);
            set_reference(_value, value);
        }

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<typename T>
    struct to<std::shared_ptr<T>> {
        using Type = std::shared_ptr<T>;

        to<std::shared_ptr<T>>(jobject instance) {
            auto proxy = get_proxy<T>(instance);
            if (proxy != nullptr) {
                _value = proxy->take_shared_ptr();
            }
        }

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<typename T>
    struct from<std::unique_ptr<T>> {
        using Type = jobject;

        from<std::unique_ptr<T>>(std::unique_ptr<T> value) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<T>::Class, constructor);
            set_reference(_value, std::move(value));
        }

        Type value() const { return _value; }

        operator Type() const { return _value; }

        Type _value;
    };

    template<typename T>
    struct to<std::unique_ptr<T>> {
        using Type = std::unique_ptr<T>;

        to<std::unique_ptr<T>>(jobject instance) {
            auto proxy = get_proxy<T>(instance);
            if (proxy != nullptr) {
                _value = std::move(proxy->take_unique_ptr());
            }
        }

        Type value() { return std::move(_value); }

        operator Type() { return std::move(_value); }

        Type _value;
    };
}

#endif //JNIWRAPPERCONCEPT_SMARTPOINTERCONVERTERS_H
