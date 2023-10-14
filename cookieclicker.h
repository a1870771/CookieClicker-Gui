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
    void cookieClicked();
    void cookieMouseOver();
    void cookieMouseOff();
    void update();
    void shineRotate();
    void buyClicker();
    void buyGrandma();
    void buyMine();
    void buyFactory();
    void buyShipment();
    void buyAlchemyLab();
    void buyPortal();
    void buyTimeMachine();

    void saveToFile();
    void loadFromFile();
    void generateGameState();
    void setGameState();
};
#endif // COOKIECLICKER_H
