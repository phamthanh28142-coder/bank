#include"Money.h"
#include<cmath>
#include<string>
Money :: Money (  long long vnd ) : vnd ( vnd ) {}
long long Money ::getVnd ( ) const noexcept {
    return vnd ; 
}
Money Money :: operator + ( const Money &right ) const {
    return Money ( vnd + right.vnd ) ; 
}
Money Money :: operator - ( const Money &right ) const {
    return Money ( vnd - right.vnd ) ; 
}
Money Money :: operator * ( const double &rate  ) const {
    return Money ( vnd * (rate / 100.0) ) ; 
}
bool Money :: isNegative ( ) const noexcept {
    return vnd < 0 ; 
}
std :: string Money :: toString ( ) const {
    return std :: to_string ( vnd) + " Vnd " ; 
}
