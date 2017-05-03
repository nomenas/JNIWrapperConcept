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

- (void) testCreateInteger {
    OCWInteger* integer = [[OCWInteger alloc] initWithValue:3];
    XCTAssertEqual(3, integer.value);
}



@end
