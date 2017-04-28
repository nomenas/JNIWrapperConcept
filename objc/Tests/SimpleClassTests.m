//
//  Tests.m
//  Tests
//
//  Created by Naum Puroski on 28/04/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "OCWInteger.h"

@interface SimpleClassTests : XCTestCase

@end

@implementation SimpleClassTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    OCWInteger* integer = [[OCWInteger alloc] initWithValue:3];
    XCTAssertEqual(3, integer.value);
}



@end
