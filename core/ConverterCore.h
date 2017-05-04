#ifndef _CONVERTERCORE_H
#define _CONVERTERCORE_H

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
    struct to<void*> : base_converter<long, void*>{
        using base_converter<long, void*>::base_converter;
    };

    template<>
    struct from<void*> {
        using Type = long;
        template<typename T>
        from<long>(T *ptr) : _value(reinterpret_cast<long>(ptr)) {};
        Type value() const { return _value; }
        Type _value;
    };
}

#define DEFINE_CONVERTER(T1, T2) \
template<> \
struct to<T1> : base_converter<T2, T1> { \
using base_converter<T2, T1>::base_converter; \
}; \
template<> \
struct from<T1> : base_converter<T1, T2> { \
using base_converter<T1, T2>::base_converter; \
}

#define DEFINE_DEFAULT_CONVERT_FUNCTION(T1, T2) \
template<> \
T2 convert<T1, T2>(const T1& value) { \
    return value; \
}

#endif  // _CONVERTERCORE_H
