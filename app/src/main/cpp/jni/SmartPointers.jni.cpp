#include <jni.h>
#include "jni_core.h"

#include "../project/SmartPointers.h"

REGISTER_CLASS(SmartPointers, "com/nomenas/wrapperconcept/project/SmartPointers")

IMPORT_REGISTERED_CLASS(Integer)

extern "C" {
    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_createRowInteger(JNIEnv *env, jclass type,
                                                                           jint value) {
        return from<Integer*>(call<SmartPointers>(&SmartPointers::createRowPointer, value), true);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_createSharedInteger(JNIEnv *env, jclass type,
                                                                              jint value) {
        return nullptr;
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_createUniqueInteger(JNIEnv *env, jclass type,
                                                                              jint value) {
        return nullptr;
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_sumRow(JNIEnv *env, jclass type, jobject arg1,
                                                                 jobject arg2) {
        return from<Integer*>(call<SmartPointers>(&SmartPointers::sum_row, to<Integer*>(arg1), to<Integer*>(arg2)), true);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_sumShared(JNIEnv *env, jclass type,
                                                                    jobject arg1, jobject arg2) {
        return nullptr;
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_sumUnique(JNIEnv *env, jclass type,
                                                                    jobject arg1, jobject arg2) {
        return nullptr;
    }

}

