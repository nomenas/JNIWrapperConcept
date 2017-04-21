
#include <jni.h>
#include "jni_core.h"

#include "../project/SingleInheritance.h"

REGISTER_CLASS(SingleInheritanceExt, "com/nomenas/wrapperconcept/project/SingleInheritanceExt")

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritanceExt_create(JNIEnv *env, jobject instance) {
        set_reference(instance, new SingleInheritanceExt(), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritanceExt_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<SingleInheritanceExt>(instance);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritanceExt_method2(JNIEnv *env, jobject instance,
                                                                         jint value) {
        return from<int>(call<SingleInheritanceExt>(instance, &SingleInheritanceExt::method2, to<int>(value)));
    }
}

