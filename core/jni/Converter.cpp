#include "Converter.h"

#include "JNIEnvFactory.h"

namespace wrapper_core {

    DEFINE_DEFAULT_CONVERT_FUNCTION(int, jint);
    DEFINE_DEFAULT_CONVERT_FUNCTION(long long, long);

    template<>
    std::string convert<jstring, std::string>(const jstring& value) {
        std::string return_value;
        auto env = JNIEnvFactory::Create();
        if (env) {
            auto text = env->GetStringUTFChars(value, 0);
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
