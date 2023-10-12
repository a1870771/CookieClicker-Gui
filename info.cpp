#include "info.h"

info::info()
{
    setCookieCount(0);
}

void info::incCookieCount(long cc){
    if (cookieCount >= cc * -1 || cc > 0){
        cookieCount += cc;
    }
}

long info::getCookieCount(){
    return cookieCount;
}
