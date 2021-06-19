#include "UniquePtr.h"
//#include "template.cpp"

using namespace std;
//template<class T>
int main() {
    int* data = new int[256];
    UniquePtr<int> ptr(data);
    cout << "ptr = " << ptr << endl;
    UniquePtr<int> p1;
    UniquePtr<int> p2(std::move(p1));
    cout << "p2 = " << p2 << endl;
    p2 = std::move(p1);
    cout << "p1 = " << p1 << endl << "p2 = " << p2 << endl;
    
    //UniquePtr p2(p1); // копирование, нельзя!

    UniquePtr<char> p3(nullptr);
    cout << "p3 = " << p3 << endl;
    //p2 = p2; // копирование, не заработает
    


    // 1. Проверить, что освобождает память после деструктора
    // 2. Проверить приведение к bool
    // 3. Проверить перемещение
    // 4. Проверить копирование (не должно работать)
    // 5. Проверить перемещение в самого себя
}