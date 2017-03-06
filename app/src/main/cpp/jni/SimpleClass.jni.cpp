//
// Created by Naum Puroski on 24/02/2017.
//

#include <jni.h>
#include "JniUtils.h"
#include <string>

#include "../project/SimpleClass.h"

extern "C" {
JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_create(JNIEnv *env, jobject instance) {
        set_reference(env, instance, new SimpleClass(), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<SimpleClass>(env, instance);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_method1(JNIEnv *env, jobject instance) {
        call<SimpleClass>(env, instance, &SimpleClass::method1);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_method2(JNIEnv *env, jobject instance, jint value) {
        return call<SimpleClass>(env, instance, &SimpleClass::method2, to<int>(env, value));
    }

    JNIEXPORT jstring JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_method3(JNIEnv *env, jobject instance, jint value, jstring text_) {
        return from<std::string>(env, call<SimpleClass>(env, instance, &SimpleClass::method3, to<int>(env, value), to<std::string>(env, text_)));
    }
}
