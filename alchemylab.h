#ifndef ALCHEMYLAB_H
#define ALCHEMYLAB_H

#include "producer.h"

class alchemyLab : public producer
{
public:
    alchemyLab(QWidget *parent = Q_NULLPTR);        // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // ALCHEMYLAB_H
