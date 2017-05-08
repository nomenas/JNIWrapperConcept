
#import "OCWSimpleClass.h"
#import "OCWSimpleClass-internal.h"
#import "OCWInteger-internal.h"

#include "SimpleClass.h"

DEFINE_WRAPPER(OCWSimpleClass, SimpleClass)

@implementation OCWSimpleClass

-(id) initWithValue: (int) value {
    self = [super init];
    if (self != nil) {
        init_proxy(_proxy, value);
    }
    return self;
}

-(void) method1 {
    call<SimpleClass>(_proxy, &SimpleClass::method1);
}

-(int) method2:(int) value {
    return call<SimpleClass>(_proxy, &SimpleClass::method2, value);
}

-(NSString*) method3WithValue:(int) value withText:(NSString*) text {
    return from<std::string>(call<SimpleClass>(_proxy, &SimpleClass::method3, value, to<std::string>(text)));
}

-(OCWInteger*) get_object {
    return from<Integer>(call<SimpleClass>(_proxy, &SimpleClass::get_object));
}

-(OCWInteger*) get_owned_item {
    return from<Integer*>(call<SimpleClass>(_proxy, &SimpleClass::get_owned_item), false);
}

-(OCWInteger*) get_item_take_ownership {
    return from<Integer*>(call<SimpleClass>(_proxy, &SimpleClass::get_item_take_ownership), true);
}

-(int) callMethodWithPtr:(OCWInteger*) obj withValue: (int) value {
    return call<SimpleClass>(_proxy, &SimpleClass::call_method_with_ptr, to<Integer*>(obj), value);
}

-(int) callMethodWithObj:(OCWInteger*) obj withValue: (int) value {
    return  call<SimpleClass>(_proxy, &SimpleClass::call_method_with_obj, to<Integer>(obj), value);
}

-(NSString*) getConstValue {
    return static_cast<NSString*>(call_and_cache<SimpleClass>("getConstValue", _proxy, &SimpleClass::get_const_value));
}

@end
