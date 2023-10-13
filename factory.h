#ifndef FACTORY_H
#define FACTORY_H

#include "producer.h"

class factory : public producer
{
public:
    factory(QWidget *parent = Q_NULLPTR);
};

#endif // FACTORY_H
