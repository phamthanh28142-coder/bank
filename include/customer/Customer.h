#pragma once

#include <string>
#include <vector>

class Customer {
    private:
        std::string customerId_;
        std::string fullName_;
        std::string phone_;
        std::string email_;

        std::vector<std::string> accountIds_;
        std::vector<std::string> cardIds_;
public:
    
    Customer(std::string customerId, std::string fullName,
             std::string phone, std::string email);

    std::string getCustomerId() const;
    std::string getFullName() const;
    std::string getPhone() const;
    std::string getEmail() const;

    std::vector<std::string> getAccountIds() const;
    std::vector<std::string> getCardIds() const;


    void addAccountId(const std::string& accountId);
    void addCardId(const std::string& cardId);


};