#include <jni.h>
#include "jni_core.h"

#include <SmartPointers.h>

REGISTER_CLASS(Integer, "com/nomenas/wrapperconcept/project/Integer")

// in case when user wants to use unique_ptr from row pointer it has to provide this type of API
namespace jni_core {
    template <>
    Integer* clone(const Integer& instance) {
        return new Integer(instance.value());
    }
}

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_Integer_create(JNIEnv *env, jobject instance, jint value) {
        set_reference(instance, new Integer(value), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_Integer_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<Integer>(instance);
    }

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_Integer_value(JNIEnv *env, jobject instance) {
        return from<int>(call<Integer>(instance, &Integer::value));
    }
}