#ifndef COOKIECLICKER_H
#define COOKIECLICKER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CookieClicker; }
QT_END_NAMESPACE

class CookieClicker : public QMainWindow
{
    Q_OBJECT

public:
    CookieClicker(QWidget *parent = nullptr);
    ~CookieClicker();

private:
    Ui::CookieClicker *ui;

public slots:
    void cookieClicked();

};
#endif // COOKIECLICKER_H
