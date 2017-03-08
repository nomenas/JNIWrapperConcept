//
// Created by Naum Puroski on 05/03/2017.
//

#ifndef WRAPPERCONCEPT_JNIUTILS_H
#define WRAPPERCONCEPT_JNIUTILS_H

#include <functional>
#include <unordered_map>

#include "Proxy.h"
#include "Converters.h"

template <typename... Args>
void call_java_void_method(jobject instance, char* method, char* signature, Args... args) {
    auto env = JNIEnvFactory::Create();
    jmethodID methodId = env->GetMethodID(env->GetObjectClass(instance), method, signature);
    env->CallVoidMethod(instance, methodId, args.value()...);
}

template <typename... Args>
long call_java_long_method(jobject instance, char* method, char* signature, Args... args) {
    auto env = JNIEnvFactory::Create();
    jmethodID methodId = env->GetMethodID(env->GetObjectClass(instance), method, signature);
    return to<long>(env->CallLongMethod(instance, methodId, args.value()...));
}

template <typename T>
T* get_reference(jobject instance) {
    auto env = JNIEnvFactory::Create();
    return reinterpret_cast<T*>(call_java_long_method(instance, "getReference", "()J"));
}

template <typename T>
void set_reference(jobject instance, T* obj, bool takeOwnership) {
    auto env = JNIEnvFactory::Create();
    call_java_void_method(instance, "setReference", "(J)V", from<void*>(new Proxy<T>(obj, takeOwnership)));
}

template <typename T>
void delete_referenced_object(jobject instance) {
    Proxy<T>* proxy = get_reference<Proxy<T>>(instance);
    if (proxy != nullptr) {
        delete proxy;
        proxy = nullptr;
        call_java_void_method(instance, "setReference", "(J)V", from<void*>(proxy));
    }
};

template <typename Class, typename Method, typename... Args>
auto call(jobject instance, Method method, Args... args) -> decltype(std::bind(method, instance, std::forward<Args>(args)...)()) {
    Proxy<Class>* proxy = get_reference<Proxy<Class>>(instance);
    return std::bind(method, proxy->subject(), std::forward<Args>(args)...)();
};

template <typename Class, typename Method, typename... Args>
jobject call_and_cache(const std::string& cache_key, jobject instance, Method method, Args... args) {
    jobject return_value = nullptr;

    auto env = JNIEnvFactory::Create();
    Proxy<Class>* proxy = get_reference<Proxy<Class>>(instance);
    if (proxy != nullptr && env) {
        return_value = proxy->get_cache_item(cache_key);
        if (return_value == nullptr) {
            return_value = from<decltype(std::bind(method, proxy->subject(), std::forward<Args>(args)...)())>(
                    std::bind(method, proxy->subject(), std::forward<Args>(args)...)());
            proxy->add_cache_item(cache_key, env->NewGlobalRef(return_value));
        }
    }

    return return_value;
};

#endif //WRAPPERCONCEPT_JNIUTILS_H
