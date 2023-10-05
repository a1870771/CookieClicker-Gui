#include "bigcookie.h"

BIGCOOKIE::BIGCOOKIE(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

BIGCOOKIE::~BIGCOOKIE() {}

void BIGCOOKIE::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
