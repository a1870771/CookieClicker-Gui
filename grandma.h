#ifndef GRANDMA_H
#define GRANDMA_H

#include "producer.h"

class grandma: public producer {
public:
    grandma(QWidget * parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values

};

#endif // GRANDMA_H
