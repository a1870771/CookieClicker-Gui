#ifndef INFO_H
#define INFO_H


class info
{
private:
    long cookieCount;
    long CPS;
public:
    info();
    ~info(){};
    long getCookieCount();
    void setCookieCount(long cc);
    void incCookieCount(long cc);

    long getCPS();
    void setCPS(long cps);
};

#endif // INFO_H
