//
// Created by Naum Puroski on 07/03/2017.
//

#ifndef JNIWRAPPERCONCEPT_PROXY_H
#define JNIWRAPPERCONCEPT_PROXY_H

#include <string>
#include <unordered_map>
#include <memory>
#include <mutex>

namespace wrapper_core {
    
    template <typename T>
    T* clone(const T& instance);
    
    template<typename T>
    class Proxy {
    public:
        Proxy<T>(T *subject, bool takeOwnership) : _subject(subject), _is_owner(takeOwnership) {}
        Proxy<T>(std::shared_ptr<T> subject) : _subject(subject.get()), _is_owner(false), _shared_ptr(subject) {}
        Proxy<T>(std::unique_ptr<T> subject) : _subject(subject.get()), _is_owner(false), _unique_ptr(std::move(subject)) {}

        ~Proxy<T>() {
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

        void add_cache_item(const std::string &key, NSObject*__strong value) {
            std::lock_guard<std::mutex> lock{_cache_mutex};
            _cache[key] = value;
        }

        NSObject* get_cache_item(const std::string &key) const {
            std::lock_guard<std::mutex> lock{_cache_mutex};
            auto iter = _cache.find(key);
            return iter != _cache.end() ? iter->second : nullptr;
        }

    private:
        T* _subject = nullptr;
        bool _is_owner = false;
        std::shared_ptr<T> _shared_ptr;
        std::unique_ptr<T> _unique_ptr;
        mutable std::mutex _cache_mutex;
        std::unordered_map<std::string, NSObject*> _cache;
    };
}

#endif //JNIWRAPPERCONCEPT_PROXY_H
