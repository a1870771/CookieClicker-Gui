#include "cookieclicker.h"
#include "ui_cookieclicker.h"
#include "bigcookie.h"


#include<QPixmap>
#include<QGraphicsDropShadowEffect>

CookieClicker::CookieClicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CookieClicker)
{
    ui->setupUi(this);

    // RESOURCE LOADING/TEXT RENDERING //
    QPixmap bigCookie("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/icon.png");
    QPixmap verticalDivider("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/panelVertical.png");
    QPixmap horizontalDivider("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/panelHorizontal.png");
    QPixmap bottomGrad("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/blackGradient.png");
    QPixmap topGrad("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/blackGradientSmallTop.png");
    QPixmap storeItem("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/storeTile.jpg");
    QPixmap cursorIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/cursor.png");
    QPixmap grandmaIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/grandma.png");
    QPixmap mineIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/mine.png");
    QPixmap factoryIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/factory.png");
    QPixmap shipmentIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/shipment.png");
    QPixmap alchemyLabIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/alchemy_lab.png");
    QPixmap portalIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/portal.png");
    QPixmap timeMachineIcon("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/time_machine.png");
    QPixmap shine("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/shine.png");

    ui->bigCookie->setPixmap(bigCookie.scaled(ui->bigCookie->width(),ui->bigCookie->height(),Qt::KeepAspectRatio));
    ui->shine->setPixmap(shine);
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

}

CookieClicker::~CookieClicker()
{
    delete ui;
}

void CookieClicker::cookieClicked(){
    ui->test->setPlainText("pissssssss");
}

