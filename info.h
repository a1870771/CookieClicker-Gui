#ifndef INFO_H
#define INFO_H

// info class handles all
class info
{
private:
    long cookieCount;
    long CPS;
public:
    info();     //default constructor initialises empty game
    ~info(){};
    long getCookieCount();  //returns total cookie count for current game
    void setCookieCount(long cc);   //sets total cookie count for current game to cc
    void incCookieCount(long cc);   //increments cookie count for current game by cc

    long getCPS();          //returns cps for current game
    void setCPS(long cps);  //sets cps for current game (used only in load() function)
};

#endif // INFO_H
