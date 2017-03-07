//
// Created by Naum Puroski on 07/03/2017.
//

#include <jni.h>

#include "JNIEnvFactory.h"

#include "ClassInfo.h"
#include "../project/SimpleClass.h"

JavaVM* JNIEnvFactory::JVM = nullptr;

extern "C" {
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*pvt*/) {
        JNIEnvFactory::JVM = vm;
        auto env = JNIEnvFactory::Create();

        if (env) {
            ClassInfo<SimpleClass>::Class = static_cast<jclass>(env->NewGlobalRef(env->FindClass(ClassInfo<SimpleClass>::Name)));
        }

        return JNIEnvFactory::JNIVersion;
    }

    JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* /*pvt*/) {
        auto env = JNIEnvFactory::Create();

        if (env != 0) {
            env->DeleteGlobalRef(ClassInfo<SimpleClass>::Class);
        }

        JNIEnvFactory::JVM = nullptr;
    }
}