#include "cookieclicker.h"
#include "ui_cookieclicker.h"
#include "bigcookie.h"
#include "info.h"

#include<QPixmap>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QMessageBox>
#include<QGraphicsDropShadowEffect>
#include<QRandomGenerator>

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

    clickerButton = ui->overlay_cursor;
    connect(clickerButton, SIGNAL(clicked()),this,SLOT(buyClicker()));

    grandmaButton = ui->overlay_grandma;
    connect(grandmaButton, SIGNAL(clicked()),this,SLOT(buyGrandma()));

    mineButton = ui->overlay_mine;
    connect(mineButton, SIGNAL(clicked()),this,SLOT(buyMine()));

    factoryButton = ui->overlay_factory;
    connect(factoryButton, SIGNAL(clicked()),this,SLOT(buyFactory()));

    shipmentButton = ui->overlay_shipment;
    connect(shipmentButton, SIGNAL(clicked()),this,SLOT(buyShipment()));

    alchemyLabButton = ui->overlay_alchemy_lab;
    connect(alchemyLabButton,SIGNAL(clicked()),this,SLOT(buyAlchemyLab()));

    portalButton = ui->overlay_portal;
    connect(portalButton,SIGNAL(clicked()),this,SLOT(buyPortal()));

    timeMachineButton = ui->overlay_time_machine;
    connect(timeMachineButton,SIGNAL(clicked()),this,SLOT(buyTimeMachine()));

    cookieNews = ui->cookie_news;
    cookieNews->setText(newsLines[0]);

    saveButton = ui->save_button;
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveToFile()));
    loadButton = ui->load_button;
    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadFromFile()));


    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            producerPics[i][j]=new QLabel(this);
            if (i == 0){
                producerPics[i][j]->setPixmap(grandmaIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,0), QSize(100,100)));
                producerPics[i][j]->hide();
            } else if(i == 1){
                producerPics[i][j]->setPixmap(mineIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,100), QSize(100,100)));
                producerPics[i][j]->hide();
            } else if(i==2){
                producerPics[i][j]->setPixmap(factoryIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,200), QSize(100,100)));
                producerPics[i][j]->hide();
            } else if(i==3){
                producerPics[i][j]->setPixmap(shipmentIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,300), QSize(100,100)));
                producerPics[i][j]->hide();
            } else if(i==4){
                producerPics[i][j]->setPixmap(alchemyLabIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,400), QSize(100,90)));
                producerPics[i][j]->hide();
            } else if(i==5){
                producerPics[i][j]->setPixmap(portalIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,500), QSize(100,70)));
                producerPics[i][j]->hide();
            } else if(i==6){
                producerPics[i][j]->setPixmap(timeMachineIcon);
                producerPics[i][j]->setGeometry(QRect(QPoint(400+65*j,600), QSize(100,100)));
                producerPics[i][j]->hide();
            }
        }
    }
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
    time++;

    for (int i=0;i<grandmaButton->getProducerCount();i++){
        if(i < 6) {
            producerPics[0][i]->show();

        }
    }
    for (int i=0;i<mineButton->getProducerCount();i++){
        if(i<6){
        producerPics[1][i]->show();
        }

    }
    for (int i=0;i<factoryButton->getProducerCount();i++){
        if(i<6){
        producerPics[2][i]->show();
        }
    }
    for (int i=0;i<shipmentButton->getProducerCount();i++){
        if(i<6){
        producerPics[3][i]->show();
        }
    }
    for (int i=0;i<alchemyLabButton->getProducerCount();i++){
        if(i<6){
        producerPics[4][i]->show();
        }
    }
    for (int i=0;i<portalButton->getProducerCount();i++){
        if(i<6){
        producerPics[5][i]->show();
        }
    }
    for (int i=0;i<timeMachineButton->getProducerCount();i++){
        if(i<6){
        producerPics[6][i]->show();
        }
    }
    GameInfo.setCPS(grandmaButton->getTotalProducerCPS()+mineButton->getTotalProducerCPS()+factoryButton->getTotalProducerCPS()+shipmentButton->getTotalProducerCPS()+alchemyLabButton->getTotalProducerCPS()+portalButton->getTotalProducerCPS()+timeMachineButton->getTotalProducerCPS());
    if (time >= 20){
        time = 0;
        tenSecondTimer++;
        GameInfo.incCookieCount(GameInfo.getCPS());
    }
    if (tenSecondTimer >= 10){
        tenSecondTimer = 0;
        GameInfo.incCookieCount(clickerButton->getProducerCount());
        int messageReset = QRandomGenerator::global()->bounded(3);
        if (messageReset == 2){
            cookieNews->setText(newsLines[QRandomGenerator::global()->bounded(9)]);
        }
    }
    ui->cookie_count->setText(QString::number(GameInfo.getCookieCount()) + " cookies");
    ui->cps_count->setText("per second: " + QString::number(GameInfo.getCPS())+"."+QString::number(clickerButton->getProducerCount()));
}

void CookieClicker::shineRotate(){
    rotationSpeed += 2;
    QPixmap shinePixmap(":/images/Assets/shine.png");
    QTransform rotation;
    rotation.rotate(rotationSpeed);
    ui->shine->setPixmap(shinePixmap.transformed(rotation));
}

void CookieClicker::buyClicker(){
    clickerButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * clickerButton->getProducerCost());
    clickerButton->setText(QString::number(clickerButton->getProducerCount()));
}

void CookieClicker::buyGrandma(){
    grandmaButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * grandmaButton->getProducerCost());
    grandmaButton->setText(QString::number(grandmaButton->getProducerCount()));
}

void CookieClicker::buyMine(){
    mineButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * mineButton->getProducerCost());
    mineButton->setText(QString::number(mineButton->getProducerCount()));
}

void CookieClicker::buyFactory(){
    factoryButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * factoryButton->getProducerCost());
    factoryButton->setText(QString::number(factoryButton->getProducerCount()));
}
void CookieClicker::buyShipment(){
    shipmentButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * shipmentButton->getProducerCost());
    shipmentButton->setText(QString::number(shipmentButton->getProducerCount()));
}

void CookieClicker::buyAlchemyLab(){
    alchemyLabButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * alchemyLabButton->getProducerCost());
    alchemyLabButton->setText(QString::number(alchemyLabButton->getProducerCount()));
}

void CookieClicker::buyPortal(){
    portalButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * portalButton->getProducerCost());
    portalButton->setText(QString::number(portalButton->getProducerCount()));
}

void CookieClicker::buyTimeMachine(){
    timeMachineButton->buyProducer(GameInfo.getCookieCount());
    GameInfo.incCookieCount(-1 * timeMachineButton->getProducerCost());
    timeMachineButton->setText(QString::number(timeMachineButton->getProducerCount()));
}

void CookieClicker::generateGameState(){
    gameState[0] = GameInfo.getCookieCount();
    gameState[1] = clickerButton->getProducerCount();
    gameState[2] = grandmaButton->getProducerCount();
    gameState[3] = mineButton->getProducerCount();
    gameState[4] = factoryButton->getProducerCount();
    gameState[5] = shipmentButton->getProducerCount();
    gameState[6] = alchemyLabButton->getProducerCount();
    gameState[7] = portalButton->getProducerCount();
    gameState[8] = timeMachineButton->getProducerCount();
}

void CookieClicker::setGameState(){
    GameInfo.setCookieCount(gameState[0]);
    clickerButton->setProducerCount(gameState[1]);
    clickerButton->setText(QString::number(clickerButton->getProducerCount()));
    grandmaButton->setProducerCount(gameState[2]);
    grandmaButton->setText(QString::number(grandmaButton->getProducerCount()));
    mineButton->setProducerCount(gameState[3]);
    mineButton->setText(QString::number(mineButton->getProducerCount()));
    factoryButton->setProducerCount(gameState[4]);
    factoryButton->setText(QString::number(factoryButton->getProducerCount()));
    shipmentButton->setProducerCount(gameState[5]);
    shipmentButton->setText(QString::number(shipmentButton->getProducerCount()));
    alchemyLabButton->setProducerCount(gameState[6]);
    alchemyLabButton->setText(QString::number(alchemyLabButton->getProducerCount()));
    portalButton->setProducerCount(gameState[7]);
    portalButton->setText(QString::number(portalButton->getProducerCount()));
    timeMachineButton->setProducerCount(gameState[8]);
    timeMachineButton->setText(QString::number(timeMachineButton->getProducerCount()));
}

void CookieClicker::saveToFile()
{
    generateGameState();
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Game"), "", tr("CookieClicker (*.cc);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        QDataStream out(&file);
        out << gameState[0] << gameState[1] << gameState[2] << gameState[3] << gameState[4] << gameState[5] << gameState[6] << gameState[7] << gameState[8];
    }
}


void CookieClicker::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Game"), "",tr("CookieClicker (*.cc);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in >> gameState[0] >> gameState[1] >> gameState[2] >> gameState[3] >> gameState[4] >> gameState[5] >> gameState[6] >> gameState[7] >> gameState[8];
    }
    setGameState();
}
