//
//  CallbackTester.h
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCWCallback.h"

typedef void (^CallbackBlock)(int value);

@interface OCWCallbackTester : NSObject

@property (readonly, nonatomic) NSInteger value;

-(id) init;
-(id) initWithValue: (int) value;

-(void) doObjectCallback: (id<OCWCallback>) callback;
-(void) doBlockCallback: (CallbackBlock) callback;

@end
