#include <iostream>

#include "Enums.h"
#include "Money.h"
#include "BankException.h"
#include "Customer.h"
#include "AccountObserver.h"

int main() {
    std::cout << "=== TEST ENUMS ===\n";
    AccountType type = AccountType::SAVINGS;
    std::cout << "Loai tai khoan: " << toString(type) << "\n";

    CardStatus status = CardStatus::ACTIVE;
    std::cout << "Trang thai the: " << toString(status) << "\n";

    std::cout << "\n=== TEST MONEY ===\n";
    Money m1(1000000);
    Money m2(500000);

    std::cout << "m1 = " << m1.toString() << "\n";
    std::cout << "m2 = " << m2.toString() << "\n";

    Money total = m1 + m2;
    std::cout << "m1 + m2 = " << total.toString() << "\n";

    Money diff = m1 - m2;
    std::cout << "m1 - m2 = " << diff.toString() << "\n";

    Money interest = m1 * 0.05;
    std::cout << "m1 * 0.05 = " << interest.toString() << "\n";

    if (m1 > m2) {
        std::cout << "m1 lon hon m2 -> dung\n";
    }

    std::cout << "\n=== TEST BANKEXCEPTION ===\n";
    try {
        Money required(2000000);
        Money available(500000);
        throw InsufficientFunds(required, available);
    }
    catch (const BankException& e) {
        std::cout << "Bat duoc loi: " << e.what() << "\n";
    }

    try {
        throw AccountFrozen("ACC001");
    }
    catch (const BankException& e) {
        std::cout << "Bat duoc loi: " << e.what() << "\n";
    }

    std::cout << "\n=== TEST CUSTOMER ===\n";
    Customer cust("CUST001", "Nguyen Van A", "0901234567", "a@email.com");
    cust.addAccountId("ACC001");
    cust.addAccountId("ACC002");
    cust.addCardId("CARD001");

    std::cout << "Ten khach hang: " << cust.getFullName() << "\n";
    std::cout << "So tai khoan: " << cust.getAccountIds().size() << "\n";
    std::cout << "So the: " << cust.getCardIds().size() << "\n";

    std::cout << "\n=== TEST OBSERVER ===\n";
    SMSNotifier sms("0901234567");
    EmailNotifier email("a@email.com");

    AccountEvent event("ACC001", EventType::WITHDRAWN, Money(200000));

    sms.update(event);
    email.update(event);

    std::cout << "\n=== TAT CA TEST CHAY XONG, KHONG CRASH ===\n";
    return 0;
}

