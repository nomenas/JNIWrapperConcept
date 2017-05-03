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

    protected:
        jobject _callback;
        const char *_name;
        const char *_signature;
    };
}

#endif //JNIWRAPPERCONCEPT_JNICALLBACK_H
