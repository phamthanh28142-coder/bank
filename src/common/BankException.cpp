#include "BankException.h"

BankException :: BankException ( const std :: string &msg) :
    std::runtime_error ( msg)  
{}
LimitExceeded :: LimitExceeded  ( const std :: string &msg) :
    BankException(msg )
{}
AccountFrozen :: AccountFrozen ( const std :: string &msg ) :
    BankException ( msg )
{}
InvalidAmount :: InvalidAmount ( const std :: string & msg) :
    BankException ( msg)
{}
StorageException :: StorageException ( const std :: string & msg) :
    BankException ( msg )
{}
InsufficientFunds :: InsufficientFunds ( const std :: string & msg) :
    BankException ( msg )
{}