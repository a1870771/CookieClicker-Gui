#ifndef MINE_H
#define MINE_H

#include "producer.h"

class mine : public producer
{
public:
    mine(QWidget *parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // MINE_H
