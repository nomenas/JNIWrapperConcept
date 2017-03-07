//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_PROXY_H
#define JNIWRAPPERCONCEPT_PROXY_H

#include <string>
#include <jni.h>
#include <unordered_map>

template <typename T>
class Proxy {
public:
    Proxy<T>(T* subject, bool takeOwnership) : _subject(subject), _isOwner(takeOwnership) {}
    ~Proxy<T>() {
        if (_isOwner && _subject) {
            delete _subject;
            _subject = nullptr;
        }
    }

    T* subject() const {
        return _subject;
    }
private:
    T* _subject;
    bool _isOwner;
    std::unordered_map<std::string, jobject> _cache;
};

#endif //JNIWRAPPERCONCEPT_PROXY_H
