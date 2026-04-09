#include <iostream>
#include <typeinfo>
#include <windows.h>
#include "Decimal.h"
#include "BitString.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int ARR_SIZE = 4;
    Array* objects[ARR_SIZE];

    objects[0] = new Decimal("12345");
    objects[1] = new Decimal("98765");
    objects[2] = new BitString("1010"); 
    objects[3] = new BitString("0111"); 

    cout << "--- Вивід справжніх типів та даних ---" << endl;
    for (int i = 0; i < ARR_SIZE; ++i) {
        cout << "Справжній тип: " << typeid(*objects[i]).name() << " | Значення: ";
        objects[i]->print();
        cout << endl;
    }

    cout << "\n--- Демонстрація віртуального додавання (add) ---" << endl;

    Array* sumDecimal = objects[0]->add(objects[1]);
    cout << "Сума Decimal: ";
    sumDecimal->print();
    cout << endl;

    Array* sumBits = objects[2]->add(objects[3]);
    cout << "Сума BitString: ";
    sumBits->print();
    cout << endl;

    cout << "\n--- Демонстрація специфічних операцій (Bitwise OR) ---" << endl;
    BitString* bs1 = dynamic_cast<BitString*>(objects[2]);
    BitString* bs2 = dynamic_cast<BitString*>(objects[3]);
    if (bs1 && bs2) {
        BitString orResult = (*bs1) | (*bs2);
        cout << "Результат 1010 OR 0111: ";
        orResult.print();
        cout << endl;
    }

    cout << "\n--- Демонстрація роботи rangeCheck() ---" << endl;
    try {
        cout << "Спроба доступу до 10-го індексу: " << (int)(*objects[0])[10] << endl;
    }
    catch (const exception& e) {
        cout << "ПЕРЕХОПЛЕНО ВИНЯТОК: " << e.what() << endl;
    }

    delete sumDecimal;
    delete sumBits;
    for (int i = 0; i < ARR_SIZE; ++i) delete objects[i];

    return 0;
}