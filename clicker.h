#ifndef CLICKER_H
#define CLICKER_H

#include "producer.h"

class clicker : public producer
{
public:
    clicker(QWidget *parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // CLICKER_H
