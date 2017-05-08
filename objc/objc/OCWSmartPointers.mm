//
//  OCWSmartPointer.m
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import "OCWSmartPointers.h"
#import "OCWSmartPointers-internal.h"
#import "OCWInteger-internal.h"

DEFINE_WRAPPER(OCWSmartPointers, SmartPointers)

@implementation OCWSmartPointers

+(OCWInteger*) createRowPointer:(int) value {
    return from<Integer*>(call<SmartPointers>(&SmartPointers::create_row_pointer, value), true);
}

+(OCWInteger*) createSharedPointer:(int) value {
    return from<std::shared_ptr<Integer>>(call<SmartPointers>(&SmartPointers::create_shared_pointer, value));
}

+(OCWInteger*) createUniquePointer:(int) value {
    return from<std::unique_ptr<Integer>>(call<SmartPointers>(&SmartPointers::create_unique_pointer, value));
}

+(OCWInteger*) sumRow:(OCWInteger*) arg1 and:(OCWInteger*) arg2 {
    return from<Integer*>(call<SmartPointers>(&SmartPointers::sum_row, to<Integer*>(arg1), to<Integer*>(arg2)), true);
}

+(OCWInteger*) sumShared:(OCWInteger*) arg1 and:(OCWInteger*) arg2 {
    return from<std::shared_ptr<Integer>>(call<SmartPointers>(&SmartPointers::sum_shared,
                                                              to<std::shared_ptr<Integer>>(arg1),
                                                              to<std::shared_ptr<Integer>>(arg2)));;
}

+(OCWInteger*) sumUnique:(OCWInteger*) arg1 and:(OCWInteger*) arg2 {
    return from<std::unique_ptr<Integer>>(call<SmartPointers>(&SmartPointers::sum_unique,
                                                              to<std::unique_ptr<Integer>>(arg1),
                                                              to<std::unique_ptr<Integer>>(arg2)));
}

@end
