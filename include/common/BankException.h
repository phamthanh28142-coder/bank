#pragma once

#include <stdexcept>
#include <string>

#include "Money.h"

class BankException : public std::runtime_error {
public:
    BankException(const std::string& message);
    virtual ~BankException() = default;
};

class InsufficientFunds : public BankException {
    private:
        Money required_;
        Money available_;
    public:
        InsufficientFunds(Money required, Money available);
        Money getRequired() const;
        Money getAvailable() const;


};

class LimitExceeded : public BankException {
    private:
        Money limit_;
        Money attempted_;
    public:
        LimitExceeded(Money limit, Money attempted);
        Money getLimit() const;
        Money getAttempted() const;


};

class AccountFrozen : public BankException {
    private:
        std::string accountId_;
    public:
        AccountFrozen(std::string accountId);
        std::string getAccountId() const;


};

class InvalidAmount : public BankException {
    private:
        Money amount_;
    public:
        InvalidAmount(Money amount);
        Money getAmount() const;

};

class StorageException : public BankException {
    private:
        std::string path_;
    public:
        StorageException(const std::string& message, std::string path);
        std::string getPath() const;


};