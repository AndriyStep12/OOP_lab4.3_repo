#pragma once
#include "Array.h"

class Decimal : public Array {
private:
    char sign;

public:
    Decimal(int s = 0, unsigned char init_val = 0, char sign = '+');
    Decimal(const std::string& numberStr);

    Array* add(const Array* other) const override;

    void print() const override;

    bool operator==(const Decimal& other) const;
};