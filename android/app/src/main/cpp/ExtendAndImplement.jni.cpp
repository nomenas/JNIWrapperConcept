#include <jni.h>
#include "jni_core.h"

#include <MultipleInheritance.h>

REGISTER_CLASS(ExtendAndImplement, "com/nomenas/wrapperconcept/project/ExtendAndImplement")

#include "ExtendAndImplement.jni.h"

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_ExtendAndImplement_create(JNIEnv *env, jobject instance) {
        set_reference(instance, new ExtendAndImplement(), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_ExtendAndImplement_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<ExtendAndImplement>(instance);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_ExtendAndImplement_method1(JNIEnv *env, jobject instance) {
        call<ExtendAndImplement>(instance, &ExtendAndImplement::method1);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_ExtendAndImplement_method2(JNIEnv *env, jobject instance,
                                                                       jint value) {
        return from<int>(call<ExtendAndImplement>(instance, &ExtendAndImplement::method2, to<int>(value)));
    }
}

