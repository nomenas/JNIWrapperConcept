//
//  CallbackTests.m
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "OCWCallback.h"
#import "OCWCallbackTester.h"

@interface CallbackTests : XCTestCase
@end

@interface CallbackHandler : NSObject <OCWCallback>
@property (nonatomic) BOOL isCalled;
@end

@implementation CallbackHandler

-(id) init {
    self = [super init];
    
    if (self != nil) {
        self.isCalled = FALSE;
    }
    
    return self;
}

-(void) somethingHappened:(int) value {
    self.isCalled = TRUE;
}

@end


@implementation CallbackTests

- (void) testObjectCallback {
    CallbackHandler* callback = [[CallbackHandler alloc] init];
    OCWCallbackTester* callbackTester = [[OCWCallbackTester alloc] init];
    [callbackTester doObjectCallback:callback];
    XCTAssertTrue(callback.isCalled);
}

- (void) testBlockCallback {
    OCWCallbackTester* callbackTester = [[OCWCallbackTester alloc] init];
    __block BOOL isCalled = FALSE;
    [callbackTester doBlockCallback:^(int argument){isCalled = TRUE;}];
    XCTAssertTrue(isCalled);
}

@end
