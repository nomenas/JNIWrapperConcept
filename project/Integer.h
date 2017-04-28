//
// Created by Naum Puroski on 28/04/2017.
//

#ifndef ANDROID_INTEGER_H
#define ANDROID_INTEGER_H

class Integer {
public:
    explicit Integer(int value) : _value(value) {}
    int value() const {return _value;}

private:
    int _value;
};

#endif //ANDROID_INTEGER_H
