#include <jni.h>
#include "jni_core.h"

#include <SmartPointers.h>

REGISTER_CLASS(SmartPointers, "com/nomenas/wrapperconcept/project/SmartPointers")

#include "Integer.jni.h"
#include "SmartPointers.jni.h"

extern "C" {
    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_createRowInteger(JNIEnv *env, jclass type,
                                                                           jint value) {
        return from<Integer*>(call<SmartPointers>(&SmartPointers::createRowPointer, value), true);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_createSharedInteger(JNIEnv *env, jclass type,
                                                                              jint value) {
        return from<std::shared_ptr<Integer>>(call<SmartPointers>(&SmartPointers::createSharedPointer, value));
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_createUniqueInteger(JNIEnv *env, jclass type,
                                                                              jint value) {
        return from<std::unique_ptr<Integer>>(call<SmartPointers>(&SmartPointers::createUniquePointer, value));
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_sumRow(JNIEnv *env, jclass type, jobject arg1,
                                                                 jobject arg2) {
        return from<Integer*>(call<SmartPointers>(&SmartPointers::sum_row, to<Integer*>(arg1), to<Integer*>(arg2)), true);
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_sumShared(JNIEnv *env, jclass type,
                                                                    jobject arg1, jobject arg2) {
        return from<std::shared_ptr<Integer>>(call<SmartPointers>(&SmartPointers::sum_shared,
            to<std::shared_ptr<Integer>>(arg1), to<std::shared_ptr<Integer>>(arg2)));
    }

    JNIEXPORT jobject JNICALL
    Java_com_nomenas_wrapperconcept_project_SmartPointers_sumUnique(JNIEnv *env, jclass type,
                                                                    jobject arg1, jobject arg2) {
        return from<std::unique_ptr<Integer>>(call<SmartPointers>(&SmartPointers::sum_unique,
            to<std::unique_ptr<Integer>>(arg1), to<std::unique_ptr<Integer>>(arg2)));
    }
}

