//
//  Tests.m
//  Tests
//
//  Created by Naum Puroski on 28/04/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "OCWInteger.h"
#import "OCWSimpleClass.h"

@interface SimpleClassTests : XCTestCase
@end

@implementation SimpleClassTests

- (void) testCreateInteger {
    OCWInteger* integer = [[OCWInteger alloc] initWithValue:3];
    XCTAssertEqual(3, integer.value);
}

- (void) testGetObject {
    OCWSimpleClass* simpleObj = [[OCWSimpleClass alloc] initWithValue: 5];
    
    OCWInteger* obj = [simpleObj get_object];
    XCTAssertNotNil(obj);
    XCTAssertEqual(5, obj.value);
}

- (void) testOwnedItem {
    OCWSimpleClass* simpleObj = [[OCWSimpleClass alloc] initWithValue: 5];
    
    OCWInteger* obj = [simpleObj get_owned_item];
    XCTAssertNotNil(obj);
    XCTAssertEqual(5, obj.value);
}

- (void) testTakeOwnership {
    OCWSimpleClass* simpleObj = [[OCWSimpleClass alloc] initWithValue: 5];
    
    OCWInteger* obj = [simpleObj get_item_take_ownership];
    XCTAssertNotNil(obj);
    XCTAssertEqual(5, obj.value);
}

- (void) testConstStringAndCache {
    OCWSimpleClass* simpleObj = [[OCWSimpleClass alloc] initWithValue: 5];
    NSString* constValue1 = [simpleObj getConstValue];
    NSString* constValue2 = [simpleObj getConstValue];
    XCTAssertNotNil(constValue1);
    XCTAssertEqual(constValue1, constValue2);
    XCTAssertTrue([[simpleObj getConstValue] isEqualToString:@"const value"]);
}

- (void) testMethodCallWithPointerArgument {
    OCWSimpleClass* simpleObj = [[OCWSimpleClass alloc] initWithValue: 5];
    OCWInteger* obj = [simpleObj get_item_take_ownership];
    XCTAssertEqual(15, [simpleObj callMethodWithPtr:obj withValue:10]);
}

- (void) testMethodCallWithObjectArgument {
    OCWSimpleClass* simpleObj = [[OCWSimpleClass alloc] initWithValue: 5];
    OCWInteger* obj = [simpleObj get_object];
    XCTAssertEqual(15, [simpleObj callMethodWithObj:obj withValue:10]);
}

@end
