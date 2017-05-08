//
// Created by Naum Puroski on 05/03/2017.
//

#ifndef WRAPPERCONCEPT_JNIUTILS_H
#define WRAPPERCONCEPT_JNIUTILS_H

#include <functional>
#include <unordered_map>

#include "Proxy.h"
#include "Converter.h"


namespace wrapper_core {
    template <typename Class, typename... Args>
    static void init_proxy(std::shared_ptr<Proxy<Class>>& ptr, Args... args) {
        ptr.reset(new wrapper_core::Proxy<Class>{new Class{args...}, true});
    }
    
    template<typename Class, typename Method, typename... Args>
    auto call(std::shared_ptr<Proxy<Class>> proxy, Method method, Args... args) -> decltype(std::bind(method, proxy->subject(), std::forward<Args>(args)...)()) {
            return std::bind(method, proxy->subject(), std::forward<Args>(args)...)();
    };
    
    template<typename Class, typename Method, typename... Args>
    auto call(Method method, Args... args) -> decltype(std::bind(method, std::forward<Args>(args)...)()) {
        return std::bind(method, std::forward<Args>(args)...)();
    };
    
    template<typename Class, typename Method, typename... Args>
    NSObject* call_and_cache(const std::string &cache_key, std::shared_ptr<Proxy<Class>> proxy, Method method, Args... args) {
        auto return_value = proxy->get_cache_item(cache_key);
        if (return_value == nullptr) {
            return_value = from<decltype(std::bind(method, proxy->subject(),
                                                   std::forward<Args>(args)...)())>(
                    std::bind(method, proxy->subject(), std::forward<Args>(args)...)());
            proxy->add_cache_item(cache_key, static_cast<NSObject*>(return_value));
        }

        return return_value;
    };
}

#define DECLARE_WRAPPER(OBJC_CLASS, CPP_CLASS) \
@interface OBJC_CLASS (Wrapper) \
- (id) initWithProxy: (std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>>) proxy; \
- (std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>>) get_proxy; \
@end \
template<> \
struct from<CPP_CLASS> { \
    using Type = OBJC_CLASS; \
    from<CPP_CLASS>(const CPP_CLASS& value) { \
        auto proxy = std::make_shared<Proxy<CPP_CLASS>>(new CPP_CLASS{value}, true); \
        _value = [[Type alloc] initWithProxy:proxy]; \
    } \
    Type* value() const { return _value; } \
    operator Type*() const { return _value; } \
    Type* _value; \
}; \
template<> \
struct to<CPP_CLASS> { \
    using Type = CPP_CLASS; \
    to<CPP_CLASS>(OBJC_CLASS* value) { \
        auto proxy = [value get_proxy]; \
        if (proxy) { \
            _value = proxy->subject(); \
        } \
    } \
    const Type& value() const { return *_value; } \
    operator const Type&() const { return *_value; } \
    Type* _value = nullptr; \
}; \
template <> \
struct from<CPP_CLASS*> { \
    using Type = OBJC_CLASS*; \
    from<CPP_CLASS*>(CPP_CLASS* value, bool takeOwnership) { \
        auto proxy = std::make_shared<Proxy<CPP_CLASS>>(value, takeOwnership); \
        _value = [[OBJC_CLASS alloc] initWithProxy:proxy]; \
    } \
    Type value() const { return _value; } \
    operator Type() const { return _value; } \
    Type _value; \
}; \
template<> \
struct to<CPP_CLASS*> { \
    using Type = CPP_CLASS*; \
    to<CPP_CLASS*>(OBJC_CLASS* value) { \
        auto proxy = [value get_proxy]; \
        if (proxy) { \
            _value = proxy->subject(); \
        } \
    } \
    Type value() const { return _value; } \
    operator Type() const { return _value; } \
    Type _value; \
}; \
template<> \
struct from<std::shared_ptr<CPP_CLASS>> { \
    using Type = OBJC_CLASS*; \
    from<std::shared_ptr<CPP_CLASS>>(std::shared_ptr<CPP_CLASS> value) { \
        auto proxy = std::make_shared<Proxy<CPP_CLASS>>(value); \
        _value = [[OBJC_CLASS alloc] initWithProxy:proxy]; \
    } \
    Type value() const { return _value; } \
    operator Type() const { return _value; } \
    Type _value; \
}; \
template<> \
struct to<std::shared_ptr<CPP_CLASS>> { \
    using Type = std::shared_ptr<CPP_CLASS>; \
    to<std::shared_ptr<CPP_CLASS>>(OBJC_CLASS* value) { \
        auto proxy = [value get_proxy]; \
        if (proxy) { \
            _value = proxy->take_shared_ptr(); \
        } \
    } \
    Type value() const { return _value; } \
    operator Type() const { return _value; } \
    Type _value; \
}; \
template<> \
struct from<std::unique_ptr<CPP_CLASS>> { \
    using Type = OBJC_CLASS*; \
    from<std::unique_ptr<CPP_CLASS>>(std::unique_ptr<CPP_CLASS> value) { \
        auto proxy = std::make_shared<Proxy<CPP_CLASS>>(std::move(value)); \
        _value = [[OBJC_CLASS alloc] initWithProxy:proxy]; \
    } \
    Type value() const { return _value; } \
    operator Type() const { return _value; } \
    Type _value; \
}; \
template<> \
struct to<std::unique_ptr<CPP_CLASS>> { \
    using Type = std::unique_ptr<CPP_CLASS>; \
    to<std::unique_ptr<CPP_CLASS>>(OBJC_CLASS* value) { \
        auto proxy = [value get_proxy]; \
        if (proxy) { \
            _value = proxy->take_unique_ptr(); \
        } \
    } \
    Type value() { return std::move(_value); } \
    operator Type() { return std::move(_value); } \
    Type _value; \
};


#define DEFINE_WRAPPER(OBJC_CLASS, CPP_CLASS) \
@interface OBJC_CLASS () \
@property (nonatomic) std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>> proxy; \
@end \
@implementation OBJC_CLASS (Wrapper) \
- (id) initWithProxy: (std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>>) proxy { \
self = [super init]; \
if (self != nil) { \
self.proxy = proxy; \
} \
return self; \
} \
- (std::shared_ptr<wrapper_core::Proxy<CPP_CLASS>>) get_proxy {\
return self.proxy;\
}\
@end

#endif //WRAPPERCONCEPT_JNIUTILS_H
