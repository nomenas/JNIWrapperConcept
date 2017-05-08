//
//  CallbackTester.m
//  objc
//
//  Created by Naum Puroski on 08/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import "OCWCallbackTester.h"
#import "OCWCallbackTester-internal.h"

DEFINE_WRAPPER(OCWCallbackTester, CallbackTester)

class CallbackWrapper : public Callback {
public:
    explicit CallbackWrapper(id<OCWCallback> callback) : _callback(callback) {}
    
    void something_happened(int arg) override {
        [_callback somethingHappened: arg];
        delete this;
    }
    
private:
    id<OCWCallback> _callback;
};
@implementation OCWCallbackTester

-(id) init {
    self = [super init];
    
    if (self != nil) {
        init_proxy(_proxy);
    }
    
    return self;
}

-(id) initWithValue: (int) value {
    self = [super init];
    
    if (self != nil) {
        init_proxy(_proxy, value);
    }
    
    return self;
}

-(void) doObjectCallback: (id<OCWCallback>) callback {
    call<CallbackTester>(_proxy, static_cast<void(CallbackTester::*)(Callback*)>(&CallbackTester::do_callback),
                         new CallbackWrapper{callback});
}

-(void) doBlockCallback: (CallbackBlock) callback {
    call<CallbackTester>(_proxy, static_cast<void(CallbackTester::*)(std::function<void(int)>)>(&CallbackTester::do_callback),
                         [&callback](int value){callback(value);});
}

@end
