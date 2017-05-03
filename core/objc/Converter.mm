//
//  Converters.m
//  objc
//
//  Created by Naum Puroski on 03/05/2017.
//  Copyright © 2017 Naum Puroski. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Converter.h"

namespace wrapper_core {
    template <>
    std::string convert<NSString*, std::string>(NSString* instance) {
        return [instance UTF8String];
    }
    
    template <>
    NSString* convert<const std::string&, NSString*>(const std::string& instance) {
        return [NSString stringWithUTF8String:instance.c_str()];;
    }
}

