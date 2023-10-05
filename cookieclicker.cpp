#include "cookieclicker.h"
#include "ui_cookieclicker.h"
#include "bigcookie.h"


#include<QPixmap>

CookieClicker::CookieClicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CookieClicker)
{
    ui->setupUi(this);

    QPixmap bigCookie("/home/jack/Documents/QT Projects/CookieClicker-Gui/Assets/icon.png");
    ui->bigCookie->setPixmap(bigCookie.scaled(ui->bigCookie->width(),ui->bigCookie->height(),Qt::KeepAspectRatio));

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
