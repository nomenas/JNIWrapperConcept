#include <jni.h>
#include "jni_core.h"

#include <SingleInheritance.h>

REGISTER_CLASS(SingleInheritance, "com/nomenas/wrapperconcept/project/SingleInheritance")

#include "SingleInheritance.jni.h"

class SingleInheritanceCustom : public SingleInheritance {
public:
    SingleInheritanceCustom(jobject callback)
            : _method2(callback, "java_overridable", "()I"){
    }

    int java_overridable() override {
        return _method2.call(&JNIEnv::CallIntMethod);
    }

private:
    wrapper_core::Callback _method2;
};

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

    JNIEXPORT jint JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritance_java_1overridable(JNIEnv *env,
                                                                                jobject instance) {
        return from<int>(call<SingleInheritance>(instance, &SingleInheritance::java_overridable));
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritanceCustom_create(JNIEnv *env,
                                                                           jobject instance) {
        set_reference(instance, new SingleInheritanceCustom(instance), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_SingleInheritanceCustom_delete(JNIEnv *env,
                                                                           jobject instance) {
        delete_referenced_object<SingleInheritanceCustom>(instance);
    }
}

