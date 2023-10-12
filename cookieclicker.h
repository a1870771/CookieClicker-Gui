#ifndef COOKIECLICKER_H
#define COOKIECLICKER_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QString>

#include "info.h"
#include "grandma.h"
#include "ui_cookieclicker.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CookieClicker; }
QT_END_NAMESPACE

class CookieClicker : public QMainWindow
{
    Q_OBJECT
    int rotationSpeed = 0;
    int time = 0;
    QTimer clock;



public:
    info GameInfo;
    CookieClicker(QWidget *parent = nullptr);
    ~CookieClicker();
    grandma *grandmaButton;

private:
    Ui::CookieClicker *ui;

public slots:
    void cookieClicked();
    void cookieMouseOver();
    void cookieMouseOff();
    void update();
    void shineRotate();
    void buyGrandma();
};
#endif // COOKIECLICKER_H
