#include "UniguePtr.h"

using namespace std;

int main() {
    char* data = new char[256];

    UniquePtr ptr(data);
    cout << "ptr = " << ptr << endl;
    UniquePtr p1;
    UniquePtr p2(std::move(p1));
    cout << "p2 = " << p2 << endl;
    p2 = std::move(p1);
    cout << "p1 = " << p1 <<  " p2 = " << p2 << endl;
    
    //UniquePtr p2(p1); // копирование, нельзя!

    UniquePtr p3(nullptr);
    cout << "p3 = " << p3 << endl;
    //p2 = p2; // копирование, не заработает
    p3 = UniquePtr(nullptr); // перемещение
    cout << "p3 = " << p3 << endl;
    


    // 1. Проверить, что освобождает память после деструктора
    // 2. Проверить приведение к bool
    // 3. Проверить перемещение
    // 4. Проверить копирование (не должно работать)
    // 5. Проверить перемещение в самого себя
}