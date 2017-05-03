//
// Created by Naum Puroski on 24/02/2017.
//

#include <jni.h>
#include "jni_core.h"

#include "SimpleClass.h"

REGISTER_CLASS(SimpleClass, "com/nomenas/wrapperconcept/project/SimpleClass")

IMPORT_REGISTERED_CLASS(Integer)
IMPORT_OBJECT_CONVERTER(Integer)

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
    Java_com_nomenas_wrapperconcept_project_SimpleClass_testObjectArgMethod(JNIEnv *env,
                                                                            jobject instance,
                                                                            jobject obj, jint value) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::test_object_arg_method, to<Integer>(obj), to<int>(value)));
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_callMethod(JNIEnv *env, jobject instance, jobject obj, jint value) {
        return from<int>(call<SimpleClass>(instance, &SimpleClass::callMethod, to<Integer*>(obj), to<int>(value)));
    }

    JNIEXPORT jstring JNICALL
    Java_com_nomenas_wrapperconcept_project_SimpleClass_getConstValue(JNIEnv *env, jobject instance) {
        return static_cast<jstring>(call_and_cache<SimpleClass>("getConstValue", instance, &SimpleClass::getConstValue));
    }
}
