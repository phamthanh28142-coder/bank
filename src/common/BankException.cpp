#include "BankException.h"

BankException::BankException(const std::string& message)
    : std::runtime_error(message) {
    // ": std::runtime_error(message)" là gọi constructor của lớp cha
    // TRƯỚC KHI thân hàm {} chạy. Gọi là "danh sách khởi tạo".
}

InsufficientFunds::InsufficientFunds(Money required, Money available)
    : BankException("So du khong du. Can: " + required.toString() +
                     ", hien co: " + available.toString()),
      required_(required),
      available_(available) {
}

Money InsufficientFunds::getRequired() const {
    return required_;
}

Money InsufficientFunds::getAvailable() const {
    return available_;
}

LimitExceeded::LimitExceeded(Money limit, Money attempted)
    : BankException("Vuot han muc. Gioi han: " + limit.toString() +
                     ", yeu cau: " + attempted.toString()),
      limit_(limit),
      attempted_(attempted) {
}

Money LimitExceeded::getLimit() const {
    return limit_;
}

Money LimitExceeded::getAttempted() const {
    return attempted_;
}

AccountFrozen::AccountFrozen(std::string accountId)
    : BankException("Tai khoan da bi dong bang: " + accountId),
      accountId_(accountId) {
}

std::string AccountFrozen::getAccountId() const {
    return accountId_;
}

InvalidAmount::InvalidAmount(Money amount)
    : BankException("So tien khong hop le: " + amount.toString()),
      amount_(amount) {
}

Money InvalidAmount::getAmount() const {
    return amount_;
}

StorageException::StorageException(const std::string& message, std::string path)
    : BankException(message + " (file: " + path + ")"),
      path_(path) {
}

std::string StorageException::getPath() const {
    return path_;
}