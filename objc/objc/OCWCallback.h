//
//  OCWCallback.h
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol OCWCallback <NSObject>

-(void) somethingHappened:(int) value;

@end
