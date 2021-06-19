//#pragma once
#include <iostream>

template<class T>
class UniquePtr 
{
private:
    T* _ptr;
public:
    // Конструктор
    UniquePtr();
    // Конструктор из указателя
    explicit UniquePtr(T* ptr);

    // Конструктор перемещения
    UniquePtr(UniquePtr<T>&& o) noexcept ;

    // Конструктор копирования
    UniquePtr(const UniquePtr<T>& o) = delete;

    // оператор присваивания через перемещение
    UniquePtr& operator=(UniquePtr<T>&& o) noexcept;

    // оператор присваивания через копирование
    UniquePtr& operator=(const UniquePtr<T>& o) = delete;

    // оператор присваивания - присвоить новый указатель
    // Не забывать про старую память
    UniquePtr& operator=(T* ptr);

    // сбрасывает _ptr в nullptr
    // не забыть почистить память память память!
    void reset();

    // reset + присвоение нового указателя
    void reset(T* ptr);

    // "Освобождение" указателя
    // без удаления памяти
    void release();

    // возвращает, внутри nullptr или нет
    operator bool() const;

    // разыменовывание
    T& operator*() const;

    // оператор стрелочки
    T* operator->() const;

    // возвращает указатель
    T* get() const;

    ~UniquePtr();

};