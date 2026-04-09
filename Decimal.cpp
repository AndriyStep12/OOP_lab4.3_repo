#include "Decimal.h"
#include <algorithm>

Decimal::Decimal(int s, unsigned char init_val, char sign)
    : Array(s, init_val), sign(sign) {
}

Decimal::Decimal(const std::string& numberStr) : Array(0, 0), sign('+') {
    std::string str = numberStr;
    if (!str.empty() && (str[0] == '-' || str[0] == '+')) {
        sign = str[0];
        str.erase(0, 1);
    }
    size = std::min((int)str.length(), MAX_SIZE);
    for (int i = 0; i < size; ++i) {
        arr[i] = str[str.length() - 1 - i] - '0';
    }
}

Array* Decimal::add(const Array* other) const {
    const Decimal* decOther = dynamic_cast<const Decimal*>(other);
    if (!decOther) throw std::invalid_argument("Несумісні типи для додавання!");

    Decimal* result = new Decimal(std::max(size, decOther->size) + 1, 0, sign);
    int carry = 0;

    for (int i = 0; i < result->size; ++i) {
        int sum = carry;
        if (i < size) sum += arr[i];
        if (i < decOther->size) sum += decOther->arr[i];

        result->arr[i] = sum % 10;
        carry = sum / 10;
    }

    while (result->size > 1 && result->arr[result->size - 1] == 0) {
        result->size--;
    }
    return result;
}

bool Decimal::operator==(const Decimal& other) const {
    if (sign != other.sign || size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != other.arr[i]) return false;
    }
    return true;
}

void Decimal::print() const {
    if (sign == '-') std::cout << "-";
    for (int i = size - 1; i >= 0; --i) {
        std::cout << (int)arr[i];
    }
}