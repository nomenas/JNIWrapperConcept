
#import "OCWSimpleClass.h"
#import "OCWSimpleClass-internal.h"
#import "OCWInteger-internal.h"

#include "SimpleClass.h"


DEFINE_WRAPPER_METHODS(OCWSimpleClass, SimpleClass)

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
//    return from<Integer>(call<SimpleClass>(_proxy, &SimpleClass::get_object));
    return nil;
}

-(OCWInteger*) get_owned_item {
    return nil;
}

-(OCWInteger*) get_item_take_ownership {
    return nil;
}

-(int) callMethodWithObj:(OCWInteger*) obj withValue: value {
    return 0;
}

-(int) testObjectMethod:(OCWInteger*) obj withValue: value {
    return 0;
}

-(NSString*) getConstValue {
    return @"test";
}

@end
