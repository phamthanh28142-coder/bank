#include "AccountObserver.h"

#include <iostream>

AccountEvent::AccountEvent(std::string accountId, EventType type, Money amount) {
    accountId_ = accountId;
    type_ = type;
    amount_ = amount;
}

std::string AccountEvent::getAccountId() const {
    return accountId_;
}

EventType AccountEvent::getType() const {
    return type_;
}

Money AccountEvent::getAmount() const {
    return amount_;
}

SMSNotifier::SMSNotifier(std::string phone) {
    phone_ = phone;
}

void SMSNotifier::update(const AccountEvent& event) {
    std::cout << "[SMS gui toi " << phone_ << "] "
              << "Tai khoan " << event.getAccountId() << ": "
              << toString(event.getType()) << " "
              << event.getAmount().toString() << "\n";
}

EmailNotifier::EmailNotifier(std::string email) {
    email_ = email;
}

void EmailNotifier::update(const AccountEvent& event) {
    std::cout << "[Email gui toi " << email_ << "] "
              << "Tai khoan " << event.getAccountId() << ": "
              << toString(event.getType()) << " "
              << event.getAmount().toString() << "\n";
}