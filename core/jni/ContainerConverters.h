//
// Created by Naum Puroski on 25/05/2017.
//

#ifndef ANDROID_CONTAINERCONVERTERS_H
#define ANDROID_CONTAINERCONVERTERS_H

#include "Converter.h"
#include "ClassInfo.h"
#include "Functional.h"
#include "ArrayList.h"
#include <vector>

extern template struct wrapper_core::ClassInfo<wrapper_core::ArrayList>;

namespace wrapper_core {
    template<typename T>
    struct from<std::vector<T>> {
        using Type = jobject;

        from<std::vector<T>>(const std::vector<T>& value) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<ArrayList>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<ArrayList>::Class, constructor);

            for (const auto& item : value) {
                call_java_method(&JNIEnv::CallBooleanMethod, _value, "add", "(Ljava/lang/Object;)Z", from<T>(item));
            }
        }

        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct to<std::vector<T>> {
        using Type = std::vector<T>;

        to<std::vector<T>>(jobject instance) {
            auto size = call_java_method(&JNIEnv::CallIntMethod, instance, "size", "()I");

            for (decltype(size) i = 0; i < size; ++i) {
                auto object = call_java_method(&JNIEnv::CallObjectMethod, instance, "get", "(I)Ljava/lang/Object;", from<decltype(i)>(i));
                if (object != nullptr) {
                    _value.push_back(to<T>(object));
                }
            }
        }

        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct from<std::shared_ptr<std::vector<T>>> {
        using Type = jobject;

        from<std::shared_ptr<std::vector<T>>>(std::shared_ptr<std::vector<T>> value) {
            _value = from<std::vector<T>>(*value);
        }

        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct to<std::shared_ptr<std::vector<T>>> {
        using Type = std::shared_ptr<std::vector<T>>;

        to<std::shared_ptr<std::vector<T>>>(jobject instance) {
            _value.reset(new std::vector<T>{});
            *_value = to<std::vector<T>>(instance);
        }

        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };
}

#endif //ANDROID_CONTAINERCONVERTERS_H
