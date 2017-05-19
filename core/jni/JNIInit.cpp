//
// Created by Naum Puroski on 07/03/2017.
//

#include <jni.h>
#include <vector>
#include <functional>

#include "JNIEnvFactory.h"

#include "ClassInfo.h"

using wrapper_core::JNIEnvFactory;
using wrapper_core::ClassInfoRegister;

JavaVM* JNIEnvFactory::JVM = nullptr;

std::vector<std::function<void(JNIEnv*)>>& wrapper_core::GetClassInitialzers() {
    static std::vector<std::function<void(JNIEnv*)>> class_initialzers;
    return class_initialzers;
}

extern "C" {
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*pvt*/) {
        JNIEnvFactory::JVM = vm;

        auto env = JNIEnvFactory::Create();
        ClassInfoRegister::InitClasses(env.get());
        return JNIEnvFactory::JNIVersion;
    }

    JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* /*pvt*/) {
        JNIEnvFactory::JVM = nullptr;
    }
}