#include <jni.h>
#include "jni_core.h"

#include <MultipleInheritance.h>

REGISTER_CLASS(BaseClass, "com/nomenas/wrapperconcept/project/BaseClass")

#include "BaseClass.jni.h"

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_BaseClass_create(JNIEnv *env, jobject instance) {
        set_reference(instance, new BaseClass(), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_BaseClass_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<BaseClass>(instance);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_BaseClass_baseClassMethod(JNIEnv *env,
                                                                                jobject instance) {
        return from<int>(call<BaseClass>(instance, &BaseClass::baseClassMethod));
    }
}