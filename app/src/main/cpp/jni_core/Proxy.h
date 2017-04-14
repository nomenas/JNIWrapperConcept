//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_PROXY_H
#define JNIWRAPPERCONCEPT_PROXY_H

#include <string>
#include <jni.h>
#include <unordered_map>
#include "JNIEnvFactory.h"

namespace jni_core {
    template<typename T>
    class Proxy {
    public:
        Proxy<T>(T *subject, bool takeOwnership) : _subject(subject), _isOwner(takeOwnership) {}

        ~Proxy<T>() {
            auto env = JNIEnvFactory::Create();
            for (auto iter = _cache.begin(); iter != _cache.end(); ++iter) {
                env->DeleteGlobalRef(iter->second);
            }

            if (_isOwner && _subject) {
                delete _subject;
                _subject = nullptr;
            }
        }

        T *subject() const {
            return _subject;
        }

        void add_cache_item(const std::string &key, jobject value) {
            _cache[key] = value;
        }

        jobject get_cache_item(const std::string &key) const {
            auto iter = _cache.find(key);
            return iter != _cache.end() ? iter->second : nullptr;
        }

    private:
        T *_subject;
        bool _isOwner;
        std::unordered_map<std::string, jobject> _cache;
    };
}

#endif //JNIWRAPPERCONCEPT_PROXY_H
