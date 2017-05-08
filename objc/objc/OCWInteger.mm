//
//  OCWInteger.m
//  objc
//
//  Created by Naum Puroski on 28/04/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import "OCWInteger.h"
#import "OCWInteger-internal.h"

DEFINE_WRAPPER(OCWInteger, Integer)

namespace wrapper_core {
    template <>
    Integer* clone(const Integer& instance) {
        return new Integer(instance.value());
    }
};

@implementation OCWInteger

- (instancetype) initWithValue: (int) value {
    self = [super init];
    if (self != nil) {
        init_proxy(_proxy, value);
    }
    return self;
}

- (NSInteger) value {
    return call<Integer>(_proxy, &Integer::value);
}

@end
