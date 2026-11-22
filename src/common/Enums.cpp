#include "Enums.h"

std::string toString(AccountType type) {
    switch (type) {
        case AccountType::SAVINGS:  return "SAVINGS";
        case AccountType::CHECKING: return "CHECKING";
        case AccountType::CREDIT:   return "CREDIT";
    }
    return "UNKNOWN";
}

std::string toString(CardStatus status) {
    switch (status) {
        case CardStatus::ACTIVE:  return "ACTIVE";
        case CardStatus::FROZEN:  return "FROZEN";
        case CardStatus::EXPIRED: return "EXPIRED";
        case CardStatus::CLOSED:  return "CLOSED";
    }
    return "UNKNOWN";
}

std::string toString(TransactionStatus status) {
    switch (status) {
        case TransactionStatus::PENDING:     return "PENDING";
        case TransactionStatus::COMPLETED:   return "COMPLETED";
        case TransactionStatus::FAILED:      return "FAILED";
        case TransactionStatus::ROLLED_BACK: return "ROLLED_BACK";
    }
    return "UNKNOWN";
}

std::string toString(EventType type) {
    switch (type) {
        case EventType::DEPOSITED:    return "DEPOSITED";
        case EventType::WITHDRAWN:    return "WITHDRAWN";
        case EventType::TRANSFERRED:  return "TRANSFERRED";
        case EventType::LOW_BALANCE:  return "LOW_BALANCE";
        case EventType::FROZEN:       return "FROZEN";
    }
    return "UNKNOWN";
}