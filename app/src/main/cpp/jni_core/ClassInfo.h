//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CLASSINFO_H
#define JNIWRAPPERCONCEPT_CLASSINFO_H

#include <jni.h>
#include <functional>
#include <vector>

namespace jni_core {
    template<typename T>
    struct ClassInfo {
        static const char *Name;
        static jclass Class;
    };

    class ClassInfoRegister {
    public:
        template<typename T>
        static void InitClass(JNIEnv *env) {
            ClassInfo<T>::Class = static_cast<jclass>(env->NewGlobalRef(
                    env->FindClass(ClassInfo<T>::Name)));
        };

        template<typename Class>
        static const char *RegisterClass(const char *name) {
            class_initialzers.push_back(std::bind(InitClass<Class>, std::placeholders::_1));
            return name;
        }

        static void InitClasses(JNIEnv *env) {
            for (const auto &initializer : class_initialzers) {
                initializer(env);
            }
        }

    private:
        static std::vector<std::function<void(JNIEnv *)>> class_initialzers;
    };
}

#define REGISTER_CLASS(CLASS, PATH) \
    template <> \
    const char* jni_core::ClassInfo<CLASS>::Name = jni_core::ClassInfoRegister::RegisterClass<CLASS>(PATH); \
    template <> \
    jclass jni_core::ClassInfo<CLASS>::Class = nullptr;

#define IMPORT_REGISTERED_CLASS(CLASS) \
    extern template struct jni_core::ClassInfo<CLASS>;

#endif //JNIWRAPPERCONCEPT_CLASSINFO_H
