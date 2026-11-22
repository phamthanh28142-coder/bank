#pragma once

#include <string>

class Money {
    private:
        long long vnd ;
    public:
        Money(long long vnd = 0);

        long long getVnd() const;

        Money operator+(const Money& other) const;
        Money operator-(const Money& other) const;
        Money operator*(double rate) const;

        bool operator==(const Money& other) const;
        bool operator<(const Money& other) const;
        bool operator>(const Money& other) const;
        bool operator<=(const Money& other) const;
        bool operator>=(const Money& other) const;

        bool isNegative() const;

        std::string toString() const;
};