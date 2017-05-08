//
//  OCWSmartPointer.h
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCWInteger.h"

@interface OCWSmartPointers : NSObject

+(OCWInteger*) createRowPointer:(int) value;
+(OCWInteger*) createSharedPointer:(int) value;
+(OCWInteger*) createUniquePointer:(int) value;

+(OCWInteger*) sumRow:(OCWInteger*) arg1 and:(OCWInteger*) arg2;
+(OCWInteger*) sumShared:(OCWInteger*) arg1 and:(OCWInteger*) arg2;
+(OCWInteger*) sumUnique:(OCWInteger*) arg1 and:(OCWInteger*) arg2;

@end
