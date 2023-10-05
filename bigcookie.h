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

protected:
    void mousePressEvent(QMouseEvent* Event);

};


#endif // BIGCOOKIE_H
