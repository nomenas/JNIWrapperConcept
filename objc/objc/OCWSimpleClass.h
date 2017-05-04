#import <Foundation/Foundation.h>

#import "OCWInteger.h"

@interface OCWSimpleClass : NSObject

-(id) initWithValue: (int) value;

-(void) method1;
-(int) method2:(int) value;
-(NSString*) method3WithValue:(int) value withText:(NSString*) text;

-(OCWInteger*) get_object;
-(OCWInteger*) get_owned_item;
-(OCWInteger*) get_item_take_ownership;

-(int) callMethodWithPtr:(OCWInteger*) obj withValue: (int) value;
-(int) callMethodWithObj:(OCWInteger*) obj withValue: (int) value;

-(NSString*) getConstValue;

@end
