#include "UniquePtr.h"

template<class T>
UniquePtr<T>::UniquePtr() {}

template<class T>
UniquePtr<T>::UniquePtr(T* ptr) {
    _ptr = ptr;
}

template<class T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& o) noexcept {
    this->_ptr = o._ptr;
    o._ptr = nullptr;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& o) noexcept {
    if (&o != this) {
        reset();
        this->_ptr = o._ptr;
        o._ptr = nullptr;
    }
    return *this;
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(T* ptr) {
    reset();
    _ptr = ptr;
    return *this;
}

template<class T>
void UniquePtr<T>::reset() {
    delete[] _ptr;
    _ptr = nullptr;
}

template<class T>
void UniquePtr<T>::reset(T* ptr) {
    reset();
    _ptr = ptr;
}

template<class T>
void UniquePtr<T>::release() {
    _ptr = nullptr;
}

template<class T>
UniquePtr<T>::operator bool() const {
    return (_ptr != nullptr);
}

template<class T>
T& UniquePtr<T>::operator*() const {
    return *_ptr;
}

template<class T>
T* UniquePtr<T>::operator->() const {
    return _ptr;
}

template<class T>
T* UniquePtr<T>::get() const {  
    return _ptr;
}

template<class T>
UniquePtr<T>::~UniquePtr() {
    reset();
}




