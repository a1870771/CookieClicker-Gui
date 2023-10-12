#include "bigcookie.h"

BIGCOOKIE::BIGCOOKIE(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

BIGCOOKIE::~BIGCOOKIE() {}

void BIGCOOKIE::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}


void BIGCOOKIE::enterEvent(QEnterEvent* event) {
    emit mouseOver();
}

void BIGCOOKIE::leaveEvent(QEvent* event) {
    emit mouseLeave();
}
