//
// Created by Naum Puroski on 05/03/2017.
//

#ifndef WRAPPERCONCEPT_JNIUTILS_H
#define WRAPPERCONCEPT_JNIUTILS_H

#include <functional>

#define FROM_BASE(FROM, TO) \
    using Type = TO; \
    from<FROM>(JNIEnv*, Type value) : _value(value){} \
    Type value() const { return _value;} \
    operator Type() const {return _value;} \
    Type _value;

#define TO_BASE(FROM, TO) \
    using Type = TO; \
    to<Type>(JNIEnv*, FROM value) : _value(value) {} \
    Type value() const {return _value;} \
    operator Type() const {return _value;} \
    Type _value;

#define CALL_CPP_VOID(ENV, INSTANCE, CLASS, METHOD) \
    CLASS* obj = get_reference<CLASS>(ENV, INSTANCE); \
    if (obj != nullptr) { \
        METHOD; \
    }

#define CALL_CPP_RETURN(ENV, INSTANCE, RETURNTYPE, DEFAULTVALUE, CLASS, METHOD) \
    from<RETURNTYPE>::Type return_value = DEFAULTVALUE; \
    CLASS* obj = get_reference<CLASS>(ENV, INSTANCE); \
    if (obj != nullptr) { \
        return_value = from<RETURNTYPE>(env, METHOD); \
    } \
    return return_value;

template <typename T>
struct from{};

template <typename T>
struct to{};

template <>
struct to<int> { TO_BASE(jint, int) };
template<>
struct from<int> { FROM_BASE(int, jint) };

template <>
struct to<long> { TO_BASE(jlong, long) };
template<>
struct from<long> { FROM_BASE(long, jlong) };

template<>
struct to<bool> { TO_BASE(jboolean, bool) };
template<>
struct from<bool> { FROM_BASE(bool, jboolean) };


template<>
struct to<void*> {
    using Type = void*; \
    to<Type>(JNIEnv*, jlong value) : _value(reinterpret_cast<void*>(value)) {} \
    Type value() const {return _value;} \
    operator Type() const {return _value;} \
    Type _value;
};
template<>
struct from<void*> {
    using Type = jlong;
    template <typename T>
    from<long>(JNIEnv*, T* ptr) : _value(reinterpret_cast<long>(ptr)){};
    Type value() const { return _value;}
    Type _value;
};

template<>
struct to<std::string> {
    using Type = std::string;
    to<Type>(JNIEnv* env, jstring value) {
        const char *text = env->GetStringUTFChars(value, 0);
        _value = text;
        env->ReleaseStringUTFChars(value, text);
    }
    Type value() const {
        return _value;
    }
    operator Type() const {return _value;}
    Type _value;
};

template<>
struct from<std::string> {
    using Type = jstring;
    from<std::string>(JNIEnv* env, const std::string& value) : _value(env->NewStringUTF(value.c_str())) {}
    Type value() const { return _value;}
    operator Type() const {return _value;}
    Type _value;
};

template <typename... Args>
void call_java_void_method(JNIEnv *env, jobject instance, char* method, char* signature, Args... args) {
    jmethodID methodId = env->GetMethodID(env->GetObjectClass(instance), method, signature);
    env->CallVoidMethod(instance, methodId, args.value()...);
}

template <typename... Args>
long call_java_long_method(JNIEnv *env, jobject instance, char* method, char* signature, Args... args) {
    jmethodID methodId = env->GetMethodID(env->GetObjectClass(instance), method, signature);
    return to<long>(env, env->CallLongMethod(instance, methodId, args.value()...));
}

template <typename T>
T* get_reference(JNIEnv *env, jobject instance) {
    return reinterpret_cast<T*>(call_java_long_method(env, instance, "getReference", "()J"));
}

template <typename T>
void set_reference(JNIEnv *env, jobject instance, T* obj, bool takeOwnership) {
    call_java_void_method(env, instance, "setReference", "(JZ)V", from<void*>(env, obj), from<bool>(env, takeOwnership));
}

template <typename T>
void delete_referenced_object(JNIEnv *env, jobject instance) {
    T* obj = reinterpret_cast<T*>(call_java_long_method(env, instance, "getReference", "()J"));
    if (obj != nullptr) {
        delete obj;
        obj = nullptr;
        call_java_void_method(env, instance, "setReference", "(J)V", from<void*>(env, obj));
    }
};

template <typename Class, typename Method, typename... Args>
auto call(Class* instance, Method method, Args... args) -> decltype(std::bind(method, instance, std::forward<Args>(args)...)()) {
    return std::bind(method, instance, std::forward<Args>(args)...)();
};

#endif //WRAPPERCONCEPT_JNIUTILS_H
