//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
#define JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H


namespace wrapper_core {
    template<typename T>
    struct from<T*> {
        using Type = jobject;
        from<T*>(T *value, bool takeOwnership) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<T>::Class, constructor);
            set_reference(_value, value, takeOwnership);
        }
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct to<T*> {
        using Type = T*;
        to<T*>(jobject value) {
            _value = get_reference<T>(value);
        }
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct from_base_object {
        using Type = jobject;
        from_base_object<T>(const T& value) {
            auto env = JNIEnvFactory::Create();
            jmethodID constructor = env->GetMethodID(ClassInfo<T>::Class, "<init>", "()V");
            _value = env->NewObject(ClassInfo<T>::Class, constructor);
            set_reference(_value, new T{value}, true);
        }
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct to_base_object {
        using Type = T;
        to_base_object<T>(jobject value) {
            _value = get_reference<T>(value);
        }
        const Type& value() const { return *_value; }
        operator const Type&() const { return *_value; }
        Type* _value = nullptr;
    };

    template<typename T>
    struct to_base_enum {
        using Type = T;
        to_base_enum <T>(jobject value) {
            auto env = JNIEnvFactory::Create();
            const auto to_string = env->GetMethodID(EnumInfo<T>::Class, "toString","()Ljava/lang/String;");
            const auto result = static_cast<jstring>(env->CallObjectMethod(value, to_string));
            const auto enum_name = env->GetStringUTFChars((jstring) result, 0);

            for (const auto& item : EnumInfo<T>::Mapping) {
                if (item.second == enum_name) {
                    _value = static_cast<T>(item.first);
                    break;
                }
            }

            env->ReleaseStringUTFChars(result, enum_name);
        }
        const Type& value() const { return _value; }
        operator const Type&() const { return _value; }
        Type _value;
    };

    template<typename T>
    struct from_base_enum {
        using Type = jobject;
        from_base_enum<T>(const T& value) {
            const auto& item = EnumInfo<T>::Mapping[value];
            if (item.size()) {
                auto env = JNIEnvFactory::Create();
                const auto field_type = std::string("L") + EnumInfo<T>::Name + ";";
                const auto field = env->GetStaticFieldID(EnumInfo<T>::Class, item.c_str(), field_type.c_str());
                _value = env->GetStaticObjectField(EnumInfo<T>::Class, field);
            }
        }
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };
}

#endif //JNIWRAPPERCONCEPT_OBJECTCONVERTERS_H
