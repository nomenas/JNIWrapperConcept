//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_PROXY_H
#define JNIWRAPPERCONCEPT_PROXY_H

#include <string>
#include <jni.h>
#include <unordered_map>
#include <memory>
#include "JNIEnvFactory.h"
#include "Clone.h"

namespace jni_core {
    template<typename T>
    class Proxy {
    public:
        Proxy<T>(T *subject, bool takeOwnership) : _subject(subject), _is_owner(takeOwnership) {}
        Proxy<T>(std::shared_ptr<T> subject) : _subject(subject.get()), _is_owner(false), _shared_ptr(subject) {}
        Proxy<T>(std::unique_ptr<T> subject) : _subject(subject.get()), _is_owner(false), _unique_ptr(std::move(subject)) {}

        ~Proxy<T>() {
            auto env = JNIEnvFactory::Create();
            for (auto iter = _cache.begin(); iter != _cache.end(); ++iter) {
                env->DeleteGlobalRef(iter->second);
            }

            if (_is_owner && _subject) {
                delete _subject;
                _subject = nullptr;
            }
        }

        T *subject() const {
            return _subject;
        }

        std::shared_ptr<T> take_shared_ptr() const {
            std::shared_ptr<T> return_value = _shared_ptr;

            if (return_value.get() == nullptr) {
                return_value.reset(clone<T>(*_subject));
            }

            return return_value;
        }

        std::unique_ptr<T> take_unique_ptr() {
            std::unique_ptr<T> return_value = std::move(_unique_ptr);

            if (return_value.get() == nullptr) {
                return_value.reset(clone<T>(*_subject));
            }

            return std::move(return_value);
        }

        void add_cache_item(const std::string &key, jobject value) {
            _cache[key] = value;
        }

        jobject get_cache_item(const std::string &key) const {
            auto iter = _cache.find(key);
            return iter != _cache.end() ? iter->second : nullptr;
        }

    private:
        T* _subject = nullptr;
        bool _is_owner = false;
        std::shared_ptr<T> _shared_ptr;
        std::unique_ptr<T> _unique_ptr;
        std::unordered_map<std::string, jobject> _cache;
    };
}

#endif //JNIWRAPPERCONCEPT_PROXY_H
