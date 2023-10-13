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
};
#endif // COOKIECLICKER_H
