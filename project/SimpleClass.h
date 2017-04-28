//
// Created by Naum Puroski on 24/02/2017.
//

#ifndef WRAPPERCONCEPT_CLASSIMPL_H
#define WRAPPERCONCEPT_CLASSIMPL_H

#include <string>

template <class T>
using owner = T;


class SimpleClass {
public:
    explicit SimpleClass(int);

    void method1() const;
    int method2(int value);
    std::string method3(int value, const std::string& text);

    SimpleClass get_object() const;
    SimpleClass* get_owned_item() const;
    owner<SimpleClass*> get_item_take_ownership() const;

    int callMethod(SimpleClass* obj, int value) const;
    int test_object_arg_method(SimpleClass obj, int value) const;

    std::string getConstValue() const;
};


#endif //WRAPPERCONCEPT_CLASSIMPL_H
