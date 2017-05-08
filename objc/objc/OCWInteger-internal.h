//
//  OCWInteger-internal.h
//  objc
//
//  Created by Naum Puroski on 28/04/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#include "objc_core.h"
#include "Integer.h"

DECLARE_WRAPPER(OCWInteger, Integer)

#define OBJC_CLASS OCWInteger
#define CPP_CLASS Integer
template<>
struct from<std::shared_ptr<CPP_CLASS>> {
    using Type = OBJC_CLASS*;
    from<std::shared_ptr<CPP_CLASS>>(std::shared_ptr<CPP_CLASS> value) {
        auto proxy = std::make_shared<Proxy<CPP_CLASS>>(value);
        _value = [[OBJC_CLASS alloc] initWithProxy:proxy];
    }
    Type value() const { return _value; }
    operator Type() const { return _value; }
    Type _value;
};

template<>
struct to<std::shared_ptr<CPP_CLASS>> {
    using Type = std::shared_ptr<CPP_CLASS>;
    to<std::shared_ptr<CPP_CLASS>>(OBJC_CLASS* value) {
        auto proxy = [value get_proxy];
        if (proxy) {
            _value = proxy->take_shared_ptr();
        }
    }
    Type value() const { return _value; }
    operator Type() const { return _value; }
    Type _value;
};

template<>
struct from<std::unique_ptr<CPP_CLASS>> {
    using Type = OBJC_CLASS*;
    from<std::unique_ptr<CPP_CLASS>>(std::unique_ptr<CPP_CLASS> value) {
        auto proxy = std::make_shared<Proxy<CPP_CLASS>>(std::move(value));
        _value = [[OBJC_CLASS alloc] initWithProxy:proxy];
    }
    Type value() const { return _value; }
    operator Type() const { return _value; }
    Type _value;
};

template<>
struct to<std::unique_ptr<CPP_CLASS>> {
    using Type = std::unique_ptr<CPP_CLASS>;
    
    to<std::unique_ptr<CPP_CLASS>>(OBJC_CLASS* value) {
        auto proxy = [value get_proxy];
        if (proxy) {
            _value = proxy->take_unique_ptr();
        }
    }
    Type value() { return std::move(_value); }
    operator Type() { return std::move(_value); }
    Type _value;
};
