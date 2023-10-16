#ifndef PORTAL_H
#define PORTAL_H

#include "producer.h"

class portal : public producer
{
public:
    portal(QWidget *parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // PORTAL_H
