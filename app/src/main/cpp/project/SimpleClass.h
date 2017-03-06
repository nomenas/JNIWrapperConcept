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
    void method1() const;
    int method2(int value);
    std::string method3(int value, const std::string& text);

    SimpleClass* get_owned_item() const;
    owner<SimpleClass*> get_item_take_ownership() const;
};


#endif //WRAPPERCONCEPT_CLASSIMPL_H
