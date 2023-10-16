#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "producer.h"

class shipment : public producer
{
public:
    shipment(QWidget *parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // SHIPMENT_H
