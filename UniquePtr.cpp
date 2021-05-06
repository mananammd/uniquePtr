#include "UniguePtr.h"

// Конструктор
UniquePtr::UniquePtr() {}

// Конструктор из указателя
UniquePtr::UniquePtr(ValueType* ptr) {
    _ptr = ptr;
}

// Конструктор перемещения
UniquePtr::UniquePtr(UniquePtr&& o) noexcept {
    this->_ptr = o._ptr;
    o._ptr = nullptr;
}

// оператор присваивания через перемещение
UniquePtr& UniquePtr::operator=(UniquePtr&& o) noexcept {
    if (&o != this) {
        reset();
        this->_ptr = o._ptr;
        o._ptr = nullptr;
    }
    return *this;
    // o == this ?
    // на этот момент тут уже что-то может быть
    // надо почистить память
}

// оператор присваивания - присвоить новый указатель
// Не забывать про старую память
UniquePtr& UniquePtr::operator=(ValueType* ptr) {
    reset();
    _ptr = ptr;
    return *this;
}

// сбрасывает _ptr в nullptr
// не забыть почистить память память память!
void UniquePtr::reset() {
    delete[] _ptr;
    _ptr = nullptr;
}

// reset + присвоение нового указателя
void UniquePtr::reset(ValueType* ptr) {
    reset();
    _ptr = ptr;
}

// "Освобождение" указателя
// без удаления памяти
void UniquePtr::release() {
    _ptr = nullptr;
}

// возвращает, внутри nullptr или нет
UniquePtr::operator bool() const {
    return (_ptr != nullptr);
}

// разыменовывание
ValueType& UniquePtr::operator*() const {
    return *_ptr;
}

// оператор стрелочки
ValueType* UniquePtr::operator->() const {
    return _ptr;
}

// возвращает указатель
ValueType* UniquePtr::get() const {  
    return _ptr;
}
UniquePtr::~UniquePtr() {
    reset();
}




