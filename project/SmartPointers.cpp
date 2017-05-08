//
// Created by Naum Puroski on 18/04/2017.
//

#include "SmartPointers.h"

Integer *SmartPointers::create_row_pointer(int value) {
    return new Integer{value};
}

std::shared_ptr<Integer> SmartPointers::create_shared_pointer(int value) {
    return std::make_shared<Integer>(value);
}

std::unique_ptr<Integer> SmartPointers::create_unique_pointer(int value) {
    return std::unique_ptr<Integer>(new Integer{value});
}

Integer *SmartPointers::sum_row(Integer *arg1, Integer *arg2) {
    return new Integer(arg1->value() + arg2->value());
}

std::shared_ptr<Integer>
SmartPointers::sum_shared(std::shared_ptr<Integer> arg1, std::shared_ptr<Integer> arg2) {
    return std::make_shared<Integer>(arg1->value() + arg2->value());
}

std::unique_ptr<Integer>
SmartPointers::sum_unique(std::unique_ptr<Integer> arg1, std::unique_ptr<Integer> arg2) {
    return std::unique_ptr<Integer>(new Integer{arg1->value() + arg2->value()});
}
