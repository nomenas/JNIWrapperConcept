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

-(int) callMethodWithObj:(OCWInteger*) obj withValue: value;
-(int) testObjectMethod:(OCWInteger*) obj withValue: value;

-(NSString*) getConstValue;

@end
