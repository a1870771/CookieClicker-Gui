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

void info::setCookieCount(long cc){
    cookieCount = cc;
}

long info::getCookieCount(){
    return cookieCount;
}

long info::getCPS(){
    return CPS;
}

void info::setCPS(long cps){
    CPS = cps;
}


