#include "cookieclicker.h"
#include "ui_cookieclicker.h"
#include "bigcookie.h"
#include "info.h"
#include "grandma.h"

#include<QPixmap>
#include<QGraphicsDropShadowEffect>

CookieClicker::CookieClicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CookieClicker)
{
    ui->setupUi(this);

    // RESOURCE LOADING;/TEXT RENDERING //
    QPixmap bigCookie(":/images/Assets/icon.png");
    QPixmap verticalDivider(":/images/Assets/panelVertical.png");
    QPixmap horizontalDivider(":/images/Assets/panelHorizontal.png");
    QPixmap bottomGrad(":/images/Assets/blackGradient.png");
    QPixmap topGrad(":/images/Assets/blackGradientSmallTop.png");
    QPixmap storeItem(":/images/Assets/storeTile.jpg");
    QPixmap cursorIcon(":/images/Assets/cursor.png");
    QPixmap grandmaIcon(":/images/Assets/grandma.png");
    QPixmap mineIcon(":/images/Assets/mine.png");
    QPixmap factoryIcon(":/images/Assets/factory.png");
    QPixmap shipmentIcon(":/images/Assets/shipment.png");
    QPixmap alchemyLabIcon(":/images/Assets/alchemy_lab.png");
    QPixmap portalIcon(":/images/Assets/portal.png");
    QPixmap timeMachineIcon(":/images/Assets/time_machine.png");



    ui->bigCookie->setPixmap(bigCookie.scaled(ui->bigCookie->width(),ui->bigCookie->height(),Qt::KeepAspectRatio));

    ui->verticalDivider->setPixmap(verticalDivider.scaled(ui->verticalDivider->width(),ui->verticalDivider->height()));
    ui->verticalDivider_2->setPixmap(verticalDivider.scaled(ui->verticalDivider->width(),ui->verticalDivider->height()));
    ui->horizDivider->setPixmap(horizontalDivider.scaled(ui->horizDivider->width(),ui->horizDivider->height()));
    ui->horizDivider_2->setPixmap(horizontalDivider.scaled(ui->horizDivider->width(),ui->horizDivider->height()));

    ui->Gradient_b->setPixmap(bottomGrad.scaled(ui->Gradient_b->width(),ui->Gradient_b->height()));
    ui->Gradient_t->setPixmap(topGrad.scaled(ui->Gradient_t->width(), ui->Gradient_t->height()));

    ui->storeItem_1->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_2->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_3->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_4->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_5->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_6->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_7->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->storeItem_8->setPixmap(storeItem.scaled(ui->storeItem_1->width(),ui->storeItem_1->height()));
    ui->icon_cursor->setPixmap(cursorIcon);
    ui->icon_grandma->setPixmap(grandmaIcon);
    ui->icon_mine->setPixmap(mineIcon);
    ui->icon_factory->setPixmap(factoryIcon);
    ui->icon_alchemy_lab->setPixmap(alchemyLabIcon);
    ui->icon_shipment->setPixmap(shipmentIcon);
    ui->icon_portal->setPixmap(portalIcon);
    ui->icon_time_machine->setPixmap(timeMachineIcon);
    ui->horizDivider_3->setPixmap(horizontalDivider);
    ui->horizDivider_4->setPixmap(horizontalDivider);
    ui->horizDivider_5->setPixmap(horizontalDivider);
    ui->horizDivider_6->setPixmap(horizontalDivider);
    ui->horizDivider_7->setPixmap(horizontalDivider);
    ui->horizDivider_8->setPixmap(horizontalDivider);
    ui->horizDivider_9->setPixmap(horizontalDivider);

    auto effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(0);
    effect->setXOffset(1);
    effect->setYOffset(1);
    ui->store_names->setGraphicsEffect(effect);


    BIGCOOKIE *cookie = ui->bigCookie;
    connect(cookie, SIGNAL(clicked()),this, SLOT(cookieClicked()));
    connect(cookie, SIGNAL(mouseOver()),this,SLOT(cookieMouseOver()));
    connect(cookie, SIGNAL(mouseLeave()),this,SLOT(cookieMouseOff()));

    connect(&clock, SIGNAL(timeout()), this, SLOT(update()));
    clock.start(50);

    grandmaButton = ui->overlay_grandma;
    connect(grandmaButton, SIGNAL(clicked()),this,SLOT(buyGrandma()));

}

CookieClicker::~CookieClicker()
{
    delete ui;
}

void CookieClicker::cookieClicked(){
    GameInfo.incCookieCount(1);

}

void CookieClicker::cookieMouseOver(){
    QPixmap bigCookieHover(":/images/Assets/icon_hover.png");
    ui->bigCookie->setPixmap(bigCookieHover.scaled(ui->bigCookie->width(), ui->bigCookie->height()));
}

void CookieClicker::cookieMouseOff() {
    QPixmap bigCookie(":/images/Assets/icon.png");
    ui->bigCookie->setPixmap(bigCookie.scaled(ui->bigCookie->width(), ui->bigCookie->height()));


}

void CookieClicker::update(){
    shineRotate();
    // get total cps
    time++;
    if (time >= 20){
        time = 0;
        // call a function which increments cookies by cps
    }
    ui->cookie_count->setText(QString::number(GameInfo.getCookieCount()) + " cookies");
}

void CookieClicker::shineRotate(){
    rotationSpeed += 2;
    QPixmap shinePixmap(":/images/Assets/shine.png");
    QTransform rotation;
    rotation.rotate(rotationSpeed);
    ui->shine->setPixmap(shinePixmap.transformed(rotation));
}

void CookieClicker::buyGrandma(){
    grandmaButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * grandmaButton->getProducerCost());
}

