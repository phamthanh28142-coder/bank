#include "Money.h"

Money::Money(long long value) {
    vnd = value;
}

long long Money::getVnd() const {
    return vnd;
}

Money Money::operator+(const Money& other) const {
    return Money(vnd + other.vnd);
}

Money Money::operator-(const Money& other) const {
    return Money(vnd - other.vnd);
}

Money Money::operator*(double rate) const {
    long long result = static_cast<long long>(vnd * rate);
    return Money(result);
}

bool Money::operator==(const Money& other) const {
    return vnd == other.vnd;
}

bool Money::operator<(const Money& other) const {
    return vnd < other.vnd;
}

bool Money::operator>(const Money& other) const {
    return vnd > other.vnd;
}

bool Money::operator<=(const Money& other) const {
    return vnd <= other.vnd;
}

bool Money::operator>=(const Money& other) const {
    return vnd >= other.vnd;
}

bool Money::isNegative() const {
    return vnd < 0;
}

std::string Money::toString() const {
    return std::to_string(vnd) + " VND";
}