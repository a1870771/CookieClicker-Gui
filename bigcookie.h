#ifndef BIGCOOKIE_H
#define BIGCOOKIE_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class BIGCOOKIE : public QLabel
{
    Q_OBJECT

public:
    explicit BIGCOOKIE(QWidget * parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());    //constructor calls qlabel constructor which creates object in parent widget
    ~BIGCOOKIE();

signals:
    void clicked(); //called when mousepressevent is called, in effect increments cookie count by one
    void mouseOver();   //called with enterEvent, changes pixmap accordingly
    void mouseLeave(); //called when leaveEvent, reverts pixmap to default

protected:
    void mousePressEvent(QMouseEvent* Event);   //called when mouse is clicked, calls clicked() in turn
    void enterEvent(QEnterEvent *ev);   //called when mouse enters object, calls mouseOver()
    void leaveEvent(QEvent *ev);    //called when mouse leaves object, calls mouseLeave()
};


#endif // BIGCOOKIE_H
