#ifndef BIGCOOKIE_H
#define BIGCOOKIE_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class BIGCOOKIE : public QLabel
{
    Q_OBJECT

public:
    explicit BIGCOOKIE(QWidget * parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~BIGCOOKIE();

signals:
    void clicked();
    void mouseOver();
    void mouseLeave();

protected:
    void mousePressEvent(QMouseEvent* Event);
    void enterEvent(QEnterEvent *ev);
    void leaveEvent(QEvent *ev);
};


#endif // BIGCOOKIE_H
