//
// Created by Naum Puroski on 05/03/2017.
//

#ifndef WRAPPERCONCEPT_JNIUTILS_H
#define WRAPPERCONCEPT_JNIUTILS_H

#include <functional>
#include <unordered_map>

#include "Proxy.h"
#include "Converters.h"


namespace wrapper_core {
    template <typename Class, typename... Args>
    static void init_proxy(std::shared_ptr<Proxy<Class>>& ptr, Args... args) {
        ptr.reset(new wrapper_core::Proxy<Class>{new Class{args...}, true});
    }
    
    template<typename Class, typename Method, typename... Args>
    auto call(std::shared_ptr<Proxy<Class>> proxy, Method method, Args... args) -> decltype(std::bind(method, proxy->subject(), std::forward<Args>(args)...)()) {
            return std::bind(method, proxy->subject(), std::forward<Args>(args)...)();
    };
    
//    template<typename... Args>
//    void call_java_void_method(jobject instance, const char *method, const char *signature,
//                               Args... args) {
//        auto env = JNIEnvFactory::Create();
//        jmethodID methodId = env->GetMethodID(env->GetObjectClass(instance), method, signature);
//        env->CallVoidMethod(instance, methodId, args.value()...);
//    }
//
//    template<typename... Args>
//    long call_java_long_method(jobject instance, const char *method, const char *signature,
//                               Args... args) {
//        auto env = JNIEnvFactory::Create();
//        jmethodID methodId = env->GetMethodID(env->GetObjectClass(instance), method, signature);
//        return to<long>(env->CallLongMethod(instance, methodId, args.value()...));
//    }
//
//    template <typename T>
//    Proxy<T>* get_proxy(jobject instance) {
//        return reinterpret_cast<Proxy<T>*>(call_java_long_method(instance, "getReference", "()J"));
//    }
//
//    template<typename T>
//    T *get_reference(jobject instance) {
//        auto proxy = get_proxy<T>(instance);
//        return proxy ? proxy->subject() : nullptr;
//    }
//
//    template<typename T>
//    void set_reference(jobject instance, T *obj, bool takeOwnership) {
//        call_java_void_method(instance, "setReference", "(J)V",
//                              from<void *>(new Proxy<T>(obj, takeOwnership)));
//    }
//
//    template<typename T>
//    void set_reference(jobject instance, std::shared_ptr<T> obj) {
//        call_java_void_method(instance, "setReference", "(J)V",
//                              from<void *>(new Proxy<T>(obj)));
//    }
//
//    template<typename T>
//    void set_reference(jobject instance, std::unique_ptr<T> obj) {
//        call_java_void_method(instance, "setReference", "(J)V",
//                              from<void *>(new Proxy<T>(std::move(obj))));
//    }
//
//    template<typename T>
//    void delete_referenced_object(jobject instance) {
//        auto proxy = get_proxy<T>(instance);
//        if (proxy != nullptr) {
//            delete proxy;
//            proxy = nullptr;
//            call_java_void_method(instance, "setReference", "(J)V", from<void *>(proxy));
//        }
//    };
//
//
//    template<typename Class, typename Method, typename... Args>
//    jobject
//    call_and_cache(const std::string &cache_key, jobject instance, Method method, Args... args) {
//        jobject return_value = nullptr;
//
//        auto env = JNIEnvFactory::Create();
//        Proxy<Class> *proxy = get_proxy<Class>(instance);
//        if (proxy != nullptr && env) {
//            return_value = proxy->get_cache_item(cache_key);
//            if (return_value == nullptr) {
//                return_value = from<decltype(std::bind(method, proxy->subject(),
//                                                       std::forward<Args>(args)...)())>(
//                        std::bind(method, proxy->subject(), std::forward<Args>(args)...)());
//                proxy->add_cache_item(cache_key, env->NewGlobalRef(return_value));
//            }
//        }
//
//        return return_value;
//    };
//
//    template<typename Class, typename Method, typename... Args>
//    auto call(Method method, Args... args) -> decltype(std::bind(method, std::forward<Args>(args)...)()) {
//        return std::bind(method, std::forward<Args>(args)...)();
//    };
}

#define DECLARE_WRAPPER_CATEGORY(OBJC_CLASS, CPP_CLASS) \
@interface OBJC_CLASS (Wrapper) \
- (id) initWithProxy: (std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>>) proxy; \
@end

#define DEFINE_WRAPPER_METHODS(OBJC_CLASS, CPP_CLASS) \
@interface OBJC_CLASS () \
@property (nonatomic) std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>> proxy; \
@end \
@implementation OBJC_CLASS (Wrapper) \
- (id) initWithProxy: (std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>>) proxy { \
self = [super init]; \
if (self != nil) { \
self.proxy = proxy; \
} \
return self; \
} \
@end

#endif //WRAPPERCONCEPT_JNIUTILS_H
