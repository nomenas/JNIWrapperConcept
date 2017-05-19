//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CLASSINFO_H
#define JNIWRAPPERCONCEPT_CLASSINFO_H

#include <jni.h>
#include <functional>
#include <vector>
#include <map>

namespace wrapper_core {
    using EnumMapping = std::map<int, std::string>;
    std::vector<std::function<void(JNIEnv*)>>& GetClassInitialzers();

    template<typename T>
    struct ClassInfo {
        static const char *Name;
        static jclass Class;
    };

    template <typename T>
    struct EnumInfo {
        static const char *Name;
        static jclass Class;
        static EnumMapping Mapping;
    };

    class ClassInfoRegister {
    public:
        template<typename T>
        static void InitClass(JNIEnv *env) {
            ClassInfo<T>::Class = static_cast<jclass>(env->NewGlobalRef(
                    env->FindClass(ClassInfo<T>::Name)));
        };

        template<typename T>
        static void InitEnum(JNIEnv *env) {
            EnumInfo<T>::Class = static_cast<jclass>(env->NewGlobalRef(
                    env->FindClass(EnumInfo<T>::Name)));
        };

        template<typename Class>
        static const char *RegisterClass(const char *name) {
            GetClassInitialzers().push_back(std::bind(InitClass<Class>, std::placeholders::_1));
            return name;
        }

        template<typename Enum>
        static const char *RegisterEnum(const char *name) {
            GetClassInitialzers().push_back(std::bind(InitEnum<Enum>, std::placeholders::_1));
            return name;
        }

        static void InitClasses(JNIEnv *env) {
            const auto& container = GetClassInitialzers();
            for (const auto &initializer : container) {
                initializer(env);
            }
        }
    };
}

#define REGISTER_CLASS(CLASS, PATH) \
    template <> \
    const char* wrapper_core::ClassInfo<CLASS>::Name = wrapper_core::ClassInfoRegister::RegisterClass<CLASS>(PATH); \
    template <> \
    jclass wrapper_core::ClassInfo<CLASS>::Class = nullptr;

#define REGISTER_ENUM(CLASS, PATH, MAPPING) \
    template <> \
    const char* wrapper_core::EnumInfo<CLASS>::Name = wrapper_core::ClassInfoRegister::RegisterEnum<CLASS>(PATH); \
    template <> \
    jclass wrapper_core::EnumInfo<CLASS>::Class = nullptr; \
    template <> \
    std::map<int, std::string> wrapper_core::EnumInfo<CLASS>::Mapping = MAPPING;

#endif //JNIWRAPPERCONCEPT_CLASSINFO_H
