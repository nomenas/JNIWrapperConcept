//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CONVERTERS_H
#define JNIWRAPPERCONCEPT_CONVERTERS_H

#include <string>

namespace wrapper_core {
    template<typename T>
    struct from {
    };

    template<typename T>
    struct to {
    };

    template<typename From, typename To>
    struct to_base {
        using Type = To;
        to_base<From, To>(From value) : _value(value) {}
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<typename From, typename To>
    struct from_base {
        using Type = To;
        from_base<From, To>(Type value) : _value(value) {}
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<>
    struct to<void*> {
        using Type = void *;
    to<Type>(long value) : _value(reinterpret_cast<void *>(value)) {}
        Type value() const { return _value; }
        operator Type() const { return _value; }
        Type _value;
    };

    template<>
    struct from<void*> {
        using Type = long;
        template<typename T>
        from<long>(T *ptr) : _value(reinterpret_cast<long>(ptr)) {};
        Type value() const { return _value; }
        Type _value;
    };
    
    template <typename From, typename To>
    To convert(From instance);
    
    template<typename From, typename To>
    struct base_object_converter {
        base_object_converter<To>(From value) {
            _value = convert<From, To>(value);
        }
        To value() const {
            return _value;
        }
        operator To() const { return _value; }
        To _value;
    };
    
    template<>
    struct to<std::string> : public base_object_converter<NSString*, std::string>{
        using base_object_converter<NSString*, std::string>::base_object_converter;
    };
    
    template<>
    struct from<std::string> :public base_object_converter<const std::string&, NSString*> {
        using base_object_converter<const std::string&, NSString*>::base_object_converter;
    };
}

#endif //JNIWRAPPERCONCEPT_CONVERTERS_H
