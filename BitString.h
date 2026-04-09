#pragma once
#include "Array.h"

class BitString : public Array {
public:
    BitString(int s = 0, unsigned char init_val = 0);
    BitString(const std::string& bitsStr);

    Array* add(const Array* other) const override;

    BitString operator&(const BitString& other) const;
    BitString operator|(const BitString& other) const;
    BitString operator^(const BitString& other) const;
    BitString operator~() const;

    BitString operator<<(int shift) const;
    BitString operator>>(int shift) const;

    void print() const override;
};