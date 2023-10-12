#include "info.h"

info::info()
{
    incCookieCount(0);
}

void info::incCookieCount(long cc){
    cookieCount += cc;
}

long info::getCookieCount(){
    return cookieCount;
}
