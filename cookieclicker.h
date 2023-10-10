#ifndef COOKIECLICKER_H
#define COOKIECLICKER_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class CookieClicker; }
QT_END_NAMESPACE

class CookieClicker : public QMainWindow
{
    Q_OBJECT
    int i = 0;
    QTimer clock;

public:

    CookieClicker(QWidget *parent = nullptr);
    ~CookieClicker();

private:
    Ui::CookieClicker *ui;

public slots:
    void cookieClicked();
    void update();
    void shineRotate(int i);
};
#endif // COOKIECLICKER_H
