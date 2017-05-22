//
// Created by Naum Puroski on 10/03/2017.
//

#include <jni.h>
#include "jni_core.h"

#include <CallbackTester.h>

REGISTER_CLASS(CallbackTester, "com/nomenas/wrapperconcept/project/CallbackTester")

#include "CallbackTester.jni.h"

class CallbackImpl : public wrapper_core::Callback, public Callback {
public:
    using wrapper_core::Callback::Callback;

    void something_happened(int arg) override {
        call(&JNIEnv::CallVoidMethod, from<int>(arg));
        delete this;
    }
};

class LambdaCallbackImpl : public wrapper_core::Callback {
public:
    using wrapper_core::Callback::Callback;
    void operator()(int value) {
        call(&JNIEnv::CallVoidMethod, from<int>(value));
        delete this;
    }
};

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_CallbackTester_create(JNIEnv *env, jobject instance, jint value) {
        set_reference(instance, new CallbackTester(to<int>(value)), true);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_CallbackTester_delete(JNIEnv *env, jobject instance) {
        delete_referenced_object<CallbackTester>(instance);
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_CallbackTester_do_1callback__Lcom_nomenas_wrapperconcept_project_Callback_2(
            JNIEnv *env, jobject instance, jobject callback) {
        call<CallbackTester>(instance, static_cast<void(CallbackTester::*)(Callback*)>(&CallbackTester::do_callback),
                             new CallbackImpl(callback, "somethingHappened", "(I)V"));
    }

    JNIEXPORT void JNICALL
    Java_com_nomenas_wrapperconcept_project_CallbackTester_do_1callback__Lcom_nomenas_wrapperconcept_project_LambdaCallback_2(
            JNIEnv *env, jobject instance, jobject callback) {
        LambdaCallbackImpl* callbackImpl = new LambdaCallbackImpl(callback, "handle", "(I)V");
        call<CallbackTester>(instance, static_cast<void(CallbackTester::*)(std::function<void(int)>)>(&CallbackTester::do_callback),
                             [callbackImpl](int value){(*callbackImpl)(value);});
    }
}


