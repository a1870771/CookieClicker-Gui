#include "cookieclicker.h"
#include "bigcookie.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CookieClicker w;
    w.show();
    return a.exec();
}
