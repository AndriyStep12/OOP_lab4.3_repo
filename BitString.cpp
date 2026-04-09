#include "BitString.h"
#include <algorithm>

BitString::BitString(int s, unsigned char init_val) : Array(s, init_val ? 1 : 0) {}

BitString::BitString(const std::string& bitsStr) : Array(0, 0) {
    size = std::min((int)bitsStr.length(), MAX_SIZE);
    for (int i = 0; i < size; ++i) {
        arr[i] = (bitsStr[bitsStr.length() - 1 - i] == '1') ? 1 : 0;
    }
}

Array* BitString::add(const Array* other) const {
    const BitString* bitOther = dynamic_cast<const BitString*>(other);
    if (!bitOther) throw std::invalid_argument("Несумісні типи!");

    BitString* result = new BitString(std::max(size, bitOther->size) + 1, 0);
    int carry = 0;

    for (int i = 0; i < result->size; ++i) {
        int sum = carry;
        if (i < size) sum += arr[i];
        if (i < bitOther->size) sum += bitOther->arr[i];

        result->arr[i] = sum % 2;
        carry = sum / 2;
    }
    while (result->size > 1 && result->arr[result->size - 1] == 0) result->size--;
    return result;
}

BitString BitString::operator|(const BitString& other) const {
    BitString result(std::max(size, other.size), 0);
    for (int i = 0; i < result.size; ++i) {
        unsigned char bit1 = (i < size) ? arr[i] : 0;
        unsigned char bit2 = (i < other.size) ? other.arr[i] : 0;
        result.arr[i] = bit1 | bit2;
    }
    return result;
}

BitString BitString::operator<<(int shift) const {
    BitString result(std::min(size + shift, MAX_SIZE), 0);
    for (int i = 0; i < size && (i + shift) < MAX_SIZE; ++i) {
        result.arr[i + shift] = arr[i];
    }
    return result;
}

void BitString::print() const {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << (int)arr[i];
    }
}