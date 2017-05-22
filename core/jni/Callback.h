//
// Created by Naum Puroski on 10/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_JNICALLBACK_H
#define JNIWRAPPERCONCEPT_JNICALLBACK_H

#include <jni.h>

#include "JNIEnvFactory.h"

namespace wrapper_core {
    class Callback {
    public:
        Callback(jobject callback, const char *name, const char *signature)
                : _name(name), _signature(signature) {
            auto env = JNIEnvFactory::Create();
            if (env) {
                _callback = env->NewGlobalRef(callback);
            }
        }

        ~Callback() {
            auto env = JNIEnvFactory::Create();
            if (env) {
                env->DeleteGlobalRef(_callback);
            }
        }

        template<typename JNIApi>
        auto call(JNIApi api) -> decltype(call_java_method(api, nullptr, nullptr, nullptr)){
            return call_java_method(api, _callback, _name, _signature);
        }

        template<typename JNIApi, typename... Args>
        auto call(JNIApi api, Args... args) -> decltype(call_java_method(api, nullptr, nullptr, nullptr, std::forward<Args...>(args...))){
            return call_java_method(api, _callback, _name, _signature, std::forward<Args...>(args...));
        }

    private:
        jobject _callback;
        const char *_name;
        const char *_signature;
    };
}

#endif //JNIWRAPPERCONCEPT_JNICALLBACK_H
