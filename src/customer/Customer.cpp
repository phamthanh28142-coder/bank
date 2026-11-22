#include "Customer.h"

Customer::Customer(std::string customerId, std::string fullName,
                    std::string phone, std::string email) {
    customerId_ = customerId;
    fullName_ = fullName;
    phone_ = phone;
    email_ = email;
    // accountIds_ va cardIds_ khong can gan gi ca, vector tu dong
    // bat dau o trang thai rong (khong co phan tu nao) khi tao moi.
}

std::string Customer::getCustomerId() const {
    return customerId_;
}

std::string Customer::getFullName() const {
    return fullName_;
}

std::string Customer::getPhone() const {
    return phone_;
}

std::string Customer::getEmail() const {
    return email_;
}

std::vector<std::string> Customer::getAccountIds() const {
    return accountIds_;
}

std::vector<std::string> Customer::getCardIds() const {
    return cardIds_;
}

void Customer::addAccountId(const std::string& accountId) {
    // push_back: thêm 1 phần tử vào CUỐI vector.
    accountIds_.push_back(accountId);
}

void Customer::addCardId(const std::string& cardId) {
    cardIds_.push_back(cardId);
}