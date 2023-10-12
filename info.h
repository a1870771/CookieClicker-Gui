#ifndef INFO_H
#define INFO_H


class info
{
private:
    long cookieCount;
public:
    info();
    ~info(){};
    long getCookieCount();
    void incCookieCount(long cc);
};

#endif // INFO_H
