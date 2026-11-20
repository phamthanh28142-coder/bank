#include<stdexcept>
#include<string>
class BankException : public std :: runtime_error {
    public: 
    BankException ( const std :: string & msg );
    virtual ~BankException () = default  ;  
};
class InsufficientFunds : public BankException { 
    public:
    InsufficientFunds ( const std :: string & msg);
};
class LimitExceeded : public BankException {
    public:
    LimitExceeded ( const std :: string & msg);
};
class AccountFrozen : public BankException {
    public:
    AccountFrozen ( const std :: string & msg);
};
class InvalidAmount : public BankException {
    public:
    InvalidAmount ( const std :: string & msg);
};
class StorageException : public BankException {
    public:
    StorageException ( const std :: string & msg);
};