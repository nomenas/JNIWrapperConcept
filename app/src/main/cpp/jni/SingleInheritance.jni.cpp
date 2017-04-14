//
// Created by Naum Puroski on 13/04/2017.
//

#include <jni.h>

#include "../project/SingleInheritance.h"

#include "Functional.h"
#include "ClassInfo.h"
#include "ObjectConverters.h"

REGISTER_CLASS(SingleInheritance, "com/nomenas/wrapperconcept/project/SingleInheritance")

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritance_create(JNIEnv *env, jobject instance) {
        set_reference(instance, new SingleInheritance(), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritance_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<SingleInheritance>(instance);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritance_method1(JNIEnv *env, jobject instance) {
        call<SingleInheritance>(instance, &SingleInheritance::method1);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritance_method2(JNIEnv *env, jobject instance,
                                                                      jint value) {
        return from<int>(call<SingleInheritance>(instance, &SingleInheritance::method2, to<int>(value)));
    }
}

