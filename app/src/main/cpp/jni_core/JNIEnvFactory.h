//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_JNIENVFACTORY_H
#define JNIWRAPPERCONCEPT_JNIENVFACTORY_H

#include <jni.h>
#include <memory>

namespace jni_core {
    using JNIEnvUniquePtr = std::unique_ptr<JNIEnv, std::function<void(JNIEnv*)>>;

    struct JNIEnvFactory {
        static JavaVM* JVM;
        static const int JNIVersion = JNI_VERSION_1_6;

        static JNIEnvUniquePtr Create() {
            JNIEnvUniquePtr return_value;

            if (JVM != nullptr) {
                JNIEnv* env = nullptr;
                int env_stat = JVM->GetEnv((void**)&env, JNIVersion);

                bool is_attached = false;
                switch (env_stat) {
                    case JNI_EDETACHED:
                        if (JVM->AttachCurrentThread(&env, 0) == 0) {
                            is_attached = true;
                        } else {
                            env = nullptr;
                        }
                        break;
                    case JNI_OK:
                        break;
                    default:
                        env = nullptr;
                        break;
                }

                if (env) {
                    return_value = JNIEnvUniquePtr{env, [is_attached](JNIEnv* env) {
                        if (is_attached ) {
                            JVM->DetachCurrentThread();
                        }
                    }};
                }
            }

            return return_value;
        }
    };
}

#endif //JNIWRAPPERCONCEPT_JNIENVFACTORY_H
