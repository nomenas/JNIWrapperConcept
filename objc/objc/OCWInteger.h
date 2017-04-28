//
//  OCWInteger.h
//  objc
//
//  Created by Naum Puroski on 28/04/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCWInteger : NSObject

@property (readonly, nonatomic) NSInteger value;

- (instancetype) initWithValue: (int) value;
    
@end
