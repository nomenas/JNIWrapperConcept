//
// Created by Naum Puroski on 24/02/2017.
//

#include <jni.h>

#include "../project/SimpleClass.h"

#include "Functional.h"
#include "ClassInfo.h"
#include "ObjectConverters.h"

template <>
const char* ClassInfo<SimpleClass>::Name = "com/nomenas/wrapperconcept/project/SimpleClass";
template <>
jclass ClassInfo<SimpleClass>::Class = nullptr;

extern "C" {
JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_create(JNIEnv*, jobject instance, jint value) {
        set_reference(instance, new SimpleClass(to<int>(value)), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_delete(JNIEnv*, jobject instance) {
        delete_referenced_object<SimpleClass>(instance);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_method1(JNIEnv*, jobject instance) {
        call<SimpleClass>(instance, &SimpleClass::method1);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_method2(JNIEnv*, jobject instance, jint value) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::method2, to<int>(value)));
    }

    JNIEXPORT jstring JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_method3(JNIEnv*, jobject instance, jint value, jstring text_) {
        return from<std::string>(call<SimpleClass>(instance, &SimpleClass::method3, to<int>(value), to<std::string>(text_)));
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getOwnedItem(JNIEnv*, jobject instance) {
        return from<SimpleClass*>(call<SimpleClass>(instance, &SimpleClass::get_owned_item), false);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getItemTakeOwnership(JNIEnv*, jobject instance) {
        return from<SimpleClass*>(call<SimpleClass>(instance, &SimpleClass::get_item_take_ownership), true);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_callMethod(JNIEnv *env, jobject instance, jobject obj, jint value) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::callMethod, to<SimpleClass*>(obj), to<int>(value)));
    }
}
