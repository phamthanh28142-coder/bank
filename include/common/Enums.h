#pragma once

enum class AccountType {
    SAVINGS,
    CHECKING,
    CREDIT,
};
enum class CardStatus{
    ACTIVE,
    FROZEN,
    EXPIRED,
    CLOSED,
};
enum class TransactionStatus{
    PENDING,
    COMPLETED,
    FAILED,
    ROLLED_BACK,
};
enum class EventType{
    DEPOSITED,
    WITHDRAWN,
    TRANSFERRED,
    LOW_BALANCE,
    FROZEN,
};
