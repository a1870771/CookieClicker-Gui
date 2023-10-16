#ifndef COOKIECLICKER_H
#define COOKIECLICKER_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QString>

#include "info.h"
#include "clicker.h"
#include "grandma.h"
#include "mine.h"
#include "factory.h"
#include "shipment.h"
#include "alchemylab.h"
#include "portal.h"
#include "timemachine.h"
#include "ui_cookieclicker.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CookieClicker; }
QT_END_NAMESPACE

class CookieClicker : public QMainWindow
{
    Q_OBJECT
    int rotationSpeed = 0;
    int time = 0;
    int tenSecondTimer = 0;
    QTimer clock;



public:
    info GameInfo;
    CookieClicker(QWidget *parent = nullptr);
    ~CookieClicker();

    grandma *grandmaButton;
    mine *mineButton;
    clicker *clickerButton;
    factory *factoryButton;
    shipment *shipmentButton;
    alchemyLab *alchemyLabButton;
    portal *portalButton;
    timeMachine *timeMachineButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    int gameState[9];
    QLabel *cookieNews;
    QString newsLines[10] = {"You feel like making cookies, but nobody wants to eat your cookies.","\"We're nice grandmas\"- Grandma","Your family accepts to try some of your cookies","\"Indentured servitude\" - Grandma","News: Cookie farms suspected of employing undeclared elderly workforce.","People are starting to talk about your cookies.","Moist Cookies","Your cookies have been placed under government surveilance.","News : man robs bank, buys cookies.","News : families around the continent report agitated, transfixed grandmothers!"};
    QLabel *producerPics[7][6];

private:
    Ui::CookieClicker *ui;

public slots:
    void cookieClicked();       //connected to bigcookie clicked() signal, increments cookie
    void cookieMouseOver();     //connected to bigcookie mouseEnter() signal, changes pixmap
    void cookieMouseOff();      //connected to bigcookie mouseLeave() signal, changes pixmap
    void update();              //connected to info timer, called every 20ms to update game state
    void shineRotate();         //called with update, rotates cookie undelay by 2 degrees every 20ms
    void buyClicker();          //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyGrandma();          //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyMine();             //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyFactory();          //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyShipment();         //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyAlchemyLab();       //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyPortal();           //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly
    void buyTimeMachine();      //connected to relevant producers clicked signal, increments count by 1 and updates cps and cookie count accordingly


    void saveToFile();          //generates a gameState array which holds producer counts and cookie counts, writes this to a .cc file
    void loadFromFile();        //reads from a .cc file into gameState array and updates relevant variables accordingly
    void generateGameState();   //called by saveToFile(), gathers up required variables and stores them in an array
    void setGameState();        //sets each index of the gameState array to the relevant variable (i.e SetcCookieCount(gameState[0]))
};
#endif // COOKIECLICKER_H
