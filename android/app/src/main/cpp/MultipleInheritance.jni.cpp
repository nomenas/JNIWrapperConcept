#include <jni.h>
#include "jni_core.h"

#include <MultipleInheritance.h>

REGISTER_CLASS(MultipleInheritance, "com/nomenas/wrapperconcept/project/MultipleInheritance")

extern "C" {
JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_MultipleInheritance_create(JNIEnv *env, jobject instance) {
        set_reference(instance, new MultipleInheritance(), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_MultipleInheritance_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<MultipleInheritance>(instance);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_MultipleInheritance_baseClassMethod(JNIEnv *env,
                                                                                jobject instance) {
        return from<int>(call<MultipleInheritance>(instance, &MultipleInheritance::baseClassMethod));
    }
}

