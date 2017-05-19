//
// Created by Naum Puroski on 24/02/2017.
//

#include <jni.h>
#include "jni_core.h"

#include "SimpleClass.h"

REGISTER_CLASS(SimpleClass, "com/nomenas/wrapperconcept/project/SimpleClass")

static EnumMapping SimpleClassStatusMapping = {
        {0, "Item1"},
        {1, "Item2"},
        {2, "Item3"}
};

REGISTER_ENUM(SimpleClass::Status, "com/nomenas/wrapperconcept/project/SimpleClass$Status", SimpleClassStatusMapping);

#include "SimpleClass.jni.h"
#include "Integer.jni.h"

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
        return from<Integer*>(call<SimpleClass>(instance, &SimpleClass::get_owned_item), false);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getItemTakeOwnership(JNIEnv*, jobject instance) {
        return from<Integer*>(call<SimpleClass>(instance, &SimpleClass::get_item_take_ownership), true);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getObject(JNIEnv *env, jobject instance) {
        return from<Integer>(call<SimpleClass>(instance, &SimpleClass::get_object));
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_callMethodWithObj(JNIEnv *env,
                                                                            jobject instance,
                                                                            jobject obj, jint value) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::call_method_with_obj, to<Integer>(obj), to<int>(value)));
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_callMethodWithPtr(JNIEnv *env, jobject instance, jobject obj, jint value) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::call_method_with_ptr, to<Integer*>(obj), to<int>(value)));
    }

    JNIEXPORT jstring JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getConstValue(JNIEnv *env, jobject instance) {
        return static_cast<jstring>(call_and_cache<SimpleClass>("getConstValue", instance, &SimpleClass::get_const_value));
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getStatus(JNIEnv *env, jobject instance) {
        return from<SimpleClass::Status>(call<SimpleClass>(instance, &SimpleClass::get_status));
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_setStatus(JNIEnv *env, jobject instance,
                                                                  jobject status) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::set_status, to<SimpleClass::Status>(status)));
    }
}
