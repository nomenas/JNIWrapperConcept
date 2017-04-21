//
// Created by Naum Puroski on 18/04/2017.
//

#ifndef JNIWRAPPERCONCEPT_SMARTPOINTERS_H
#define JNIWRAPPERCONCEPT_SMARTPOINTERS_H

#include <memory>

class Integer {
public:
    explicit Integer(int value) : _value(value) {}
    int value() const {return _value;}

private:
    int _value;
};

class SmartPointers {
public:
    static Integer* createRowPointer(int value);
    static std::shared_ptr<Integer> createSharedPointer(int value);
    static std::unique_ptr<Integer> createUniquePointer(int value);

    static Integer* sum_row(Integer* arg1, Integer* arg2);
    static std::shared_ptr<Integer> sum_shared(std::shared_ptr<Integer> arg1, std::shared_ptr<Integer> arg2);
    static std::unique_ptr<Integer> sum_unique(std::unique_ptr<Integer> arg1, std::unique_ptr<Integer> arg2);
};


#endif //JNIWRAPPERCONCEPT_SMARTPOINTERS_H
