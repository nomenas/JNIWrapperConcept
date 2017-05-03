#include "Converter.h"

#define DEFINE_COMPATIBLE_CONVERTER(T1, T2) \
template<> \
T2 convert<T1, T2>(const T1& value) { \
    return value; \
}

namespace wrapper_core {

    DEFINE_COMPATIBLE_CONVERTER(int, jint);
    DEFINE_COMPATIBLE_CONVERTER(long long, long);

    template<>
    std::string convert<jstring, std::string>(const jstring& value) {
        std::string return_value;
        auto env = JNIEnvFactory::Create();
        if (env) {
            const char *text = env->GetStringUTFChars(value, 0);
            return_value = text;
            env->ReleaseStringUTFChars(value, text);
        }

        return return_value;
    }


    template <>
    jstring convert<std::string, jstring>(const std::string& instance) {
        jstring return_value = nullptr;
        auto env = JNIEnvFactory::Create();
        if (env) {
            return_value = env->NewStringUTF(instance.c_str());
        }
        return return_value;
    }
}
