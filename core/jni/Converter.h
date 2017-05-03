//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CONVERTERS_H
#define JNIWRAPPERCONCEPT_CONVERTERS_H

#include "JNIEnvFactory.h"

#define DEFINE_CONVERTER(T1, T2) \
template<> \
struct to<T1> : base_converter<T2, T1> { \
    using base_converter<T2, T1>::base_converter; \
}; \
template<> \
struct from<T1> : base_converter<T1, T2> { \
    using base_converter<T1, T2>::base_converter; \
}

namespace wrapper_core {
    template<typename T>
    struct from {
    };

    template<typename T>
    struct to {
    };

    template <typename From, typename To>
    To convert(const From& value);

    template<typename From, typename To>
    struct base_converter {
        base_converter<From, To>(const From& value) : _value(convert<From, To>(value)) {}
        To value() const { return _value; }
        operator To() const { return _value; }
        To _value;
    };

    template<>
    struct to<void*> : base_converter<jlong, void*>{
        using base_converter<jlong, void*>::base_converter;
    };

    template<>
    struct from<void*> {
        using Type = jlong;
        template<typename T>
        from<long>(T *ptr) : _value(reinterpret_cast<long>(ptr)) {};
        Type value() const { return _value; }
        Type _value;
    };

    DEFINE_CONVERTER(int, jint);
    DEFINE_CONVERTER(long, jlong);
    DEFINE_CONVERTER(bool, jboolean);
    DEFINE_CONVERTER(std::string, jstring);
}

#endif //JNIWRAPPERCONCEPT_CONVERTERS_H
