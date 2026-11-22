#pragma once

#include <string>

#include "Enums.h"
#include "Money.h"

// AccountEvent: ghi lại thông tin 1 sự kiện vừa xảy ra trên tài khoản
// (ví dụ: vừa rút 500.000 VND khỏi tài khoản ACC001).
class AccountEvent {
public:
    AccountEvent(std::string accountId, EventType type, Money amount);

    std::string getAccountId() const;
    EventType getType() const;
    Money getAmount() const;

private:
    std::string accountId_;
    EventType type_;
    Money amount_;
};

// Observer: INTERFACE - chỉ quy định "phải có hàm update", không viết
// logic cụ thể ở đây. Bất kỳ class nào muốn nhận thông báo sự kiện
// đều phải kế thừa từ Observer và tự viết hàm update() của riêng mình.
class Observer {
public:
    virtual ~Observer() = default;   // destructor ảo, vì đây là lớp cha

    // "= 0" nghĩa là hàm thuần ảo (pure virtual): không có code ở đây,
    // lớp con BẮT BUỘC phải tự định nghĩa hàm này.
    virtual void update(const AccountEvent& event) = 0;
};

// SMSNotifier: 1 cách thông báo cụ thể - gửi tin nhắn SMS.
// ": public Observer" + viết lại hàm update() -> gọi là
// "hiện thực interface" (implement interface).
class SMSNotifier : public Observer {
public:
    SMSNotifier(std::string phone);

    // "override": xác nhận với compiler đây là hàm ĐANG VIẾT LẠI
    // (ghi đè) hàm ảo của lớp cha, giúp bắt lỗi nếu gõ sai tên/tham số.
    void update(const AccountEvent& event) override;

private:
    std::string phone_;
};

// EmailNotifier: 1 cách thông báo khác - gửi email.
class EmailNotifier : public Observer {
public:
    EmailNotifier(std::string email);

    void update(const AccountEvent& event) override;

private:
    std::string email_;
};