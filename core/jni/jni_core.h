//
// Created by Naum Puroski on 14/04/2017.
//

#ifndef JNIWRAPPERCONCEPT_JNI_CORE_H
#define JNIWRAPPERCONCEPT_JNI_CORE_H

#include "Functional.h"
#include "ClassInfo.h"
#include "Converter.h"
#include "ObjectConverters.h"
#include "SmartPointerConverters.h"
#include "Callback.h"

using wrapper_core::call_java_void_method;
using wrapper_core::set_reference;
using wrapper_core::delete_referenced_object;
using wrapper_core::call;
using wrapper_core::call_and_cache;
using wrapper_core::from;
using wrapper_core::to;
using wrapper_core::EnumMapping;

#endif //JNIWRAPPERCONCEPT_JNI_CORE_H
