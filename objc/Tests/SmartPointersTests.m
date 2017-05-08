//
//  SmartPointersTests.m
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "OCWSmartPointers.h"
#import "OCWInteger.h"

@interface SmartPointersTests : XCTestCase
@end

@implementation SmartPointersTests

- (void) testCreateAndUseRowPointer {
    OCWInteger* arg1 = [OCWSmartPointers createRowPointer:10];
    XCTAssertNotNil(arg1);
    OCWInteger* arg2 = [OCWSmartPointers createRowPointer:5];
    XCTAssertNotNil(arg2);
    
    OCWInteger* result_row = [OCWSmartPointers sumRow:arg1 and:arg2];
    XCTAssertNotNil(result_row);
    XCTAssertEqual(15, result_row.value);
    
    OCWInteger* result_shared = [OCWSmartPointers sumShared:arg1 and: arg2];
    XCTAssertNotNil(result_shared);
    XCTAssertEqual(15, result_shared.value);
    
    OCWInteger* result_unique = [OCWSmartPointers sumUnique:arg1 and: arg2];
    XCTAssertNotNil(result_unique);
    XCTAssertEqual(15, result_unique.value);
}

- (void) testCreateAndUseSmartPointer {
    OCWInteger* arg1 = [OCWSmartPointers createSharedPointer:10];
    XCTAssertNotNil(arg1);
    OCWInteger* arg2 = [OCWSmartPointers createSharedPointer:5];
    XCTAssertNotNil(arg2);
    
    OCWInteger* result_row = [OCWSmartPointers sumRow:arg1 and:arg2];
    XCTAssertNotNil(result_row);
    XCTAssertEqual(15, result_row.value);
    
    OCWInteger* result_shared = [OCWSmartPointers sumShared:arg1 and: arg2];
    XCTAssertNotNil(result_shared);
    XCTAssertEqual(15, result_shared.value);
    
    OCWInteger* result_unique = [OCWSmartPointers sumUnique:arg1 and: arg2];
    XCTAssertNotNil(result_unique);
    XCTAssertEqual(15, result_unique.value);
}

- (void) testCreateAndUseUniquePointer {
    OCWInteger* arg1 = [OCWSmartPointers createUniquePointer:10];
    XCTAssertNotNil(arg1);
    OCWInteger* arg2 = [OCWSmartPointers createUniquePointer:5];
    XCTAssertNotNil(arg2);
    
    OCWInteger* result_row = [OCWSmartPointers sumRow:arg1 and:arg2];
    XCTAssertNotNil(result_row);
    XCTAssertEqual(15, result_row.value);
    
    OCWInteger* result_shared = [OCWSmartPointers sumShared:arg1 and: arg2];
    XCTAssertNotNil(result_shared);
    XCTAssertEqual(15, result_shared.value);
    
    OCWInteger* result_unique = [OCWSmartPointers sumUnique:arg1 and: arg2];
    XCTAssertNotNil(result_unique);
    XCTAssertEqual(15, result_unique.value);
}

@end
