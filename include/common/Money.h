#pragma once
#include<compare>
#include<cstdint>
#include<string>
#include<cmath> 

class Money{
    private : 
    long long vnd ;
    public :
    explicit Money (  long long vnd = 0 ) ; 
    long long getVnd ( ) const noexcept ;
    Money operator + ( const Money &right) const ;
    Money operator - ( const Money &right) const ;
    Money operator * ( const double &rate  ) const ;
    std::strong_ordering operator <=> ( const Money & right ) const noexcept = default ;
    bool isNegative ( ) const noexcept; 
    std :: string toString ( ) const ; 
};           