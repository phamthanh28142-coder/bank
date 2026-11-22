#pragma once

#include <string>

// enum class: định nghĩa 1 kiểu dữ liệu chỉ nhận một trong các giá trị
// liệt kê sẵn. An toàn hơn enum thường vì phải viết đầy đủ TenEnum::GiaTri.

enum class AccountType {
    SAVINGS,
    CHECKING,
    CREDIT,
};

enum class CardStatus {
    ACTIVE,
    FROZEN,
    EXPIRED,
    CLOSED,
};

enum class TransactionStatus {
    PENDING,
    COMPLETED,
    FAILED,
    ROLLED_BACK,
};

enum class EventType {
    DEPOSITED,
    WITHDRAWN,
    TRANSFERRED,
    LOW_BALANCE,
    FROZEN,
};

// Chỉ khai báo chữ ký hàm ở đây. Phần cài đặt (switch-case) nằm trong Enums.cpp.
std::string toString(AccountType type);
std::string toString(CardStatus status);
std::string toString(TransactionStatus status);
std::string toString(EventType type);