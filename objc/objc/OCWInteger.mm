//
//  OCWInteger.m
//  objc
//
//  Created by Naum Puroski on 28/04/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import "OCWInteger.h"

#include "Integer.h"

@implementation OCWInteger

- (instancetype) initWithValue: (int) value {
    self = [super init];
    if (self != nil) {
//        _value = value;
    }
    return self;
}

- (NSInteger) value {
    return 5;
}

@end
