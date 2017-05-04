//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_CONVERTERS_H
#define JNIWRAPPERCONCEPT_CONVERTERS_H

#include "../ConverterCore.h"
#include "Proxy.h"
#include <string>

namespace wrapper_core {
    DEFINE_CONVERTER(std::string, NSString*);
}

#endif //JNIWRAPPERCONCEPT_CONVERTERS_H
