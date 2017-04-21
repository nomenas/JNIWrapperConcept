//
// Created by Naum Puroski on 24/02/2017.
//

#ifndef WRAPPERCONCEPT_CLASSCALLBACK_H
#define WRAPPERCONCEPT_CLASSCALLBACK_H

class Callback {
public:
    virtual ~Callback() = default;

    virtual void something_happened(int arg) = 0;
};

#endif //WRAPPERCONCEPT_CLASSCALLBACK_H
