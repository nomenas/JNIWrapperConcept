//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CLASSINFO_H
#define JNIWRAPPERCONCEPT_CLASSINFO_H

#include <jni.h>
#include <functional>
#include <vector>

template <typename T>
struct ClassInfo {
    static const char* Name;
    static jclass Class;
};

class ClassInfoRegister {
public:
    template<typename T>
    static void InitClass(JNIEnv* env) {
        ClassInfo<T>::Class = static_cast<jclass>(env->NewGlobalRef(env->FindClass(ClassInfo<T>::Name)));
    };

    template <typename Class>
    static const char* RegisterClass(const char* name) {
        class_initialzers.push_back(std::bind(InitClass<Class>, std::placeholders::_1));
        return name;
    }

    static void InitClasses(JNIEnv* env) {
        for (const auto& initializer : class_initialzers) {
            initializer(env);
        }
    }

private:
    static std::vector<std::function<void(JNIEnv*)>> class_initialzers;
};

#define REGISTER_CLASS(CLASS, PATH) \
    template <> \
    const char* ClassInfo<CLASS>::Name = ClassInfoRegister::RegisterClass<CLASS>(PATH); \
    template <> \
    jclass ClassInfo<CLASS>::Class = nullptr;

#endif //JNIWRAPPERCONCEPT_CLASSINFO_H
