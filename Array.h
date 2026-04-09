#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char arr[MAX_SIZE];
    int size;

    void rangeCheck(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Помилка: Індекс виходить за межі масиву!");
        }
    }

public:

    Array(int s = 0, unsigned char init_val = 0) {
        size = (s > MAX_SIZE) ? MAX_SIZE : s;
        for (int i = 0; i < size; ++i) {
            arr[i] = init_val;
        }
    }

    virtual ~Array() = default;


    unsigned char& operator[](int index) {
        rangeCheck(index);
        return arr[index];
    }

    const unsigned char& operator[](int index) const {
        rangeCheck(index);
        return arr[index];
    }

    int getSize() const { return size; }


    virtual Array* add(const Array* other) const = 0;
    virtual void print() const = 0;
};