#include "portal.h"

portal::portal(QWidget* parent)
    :
    producer(parent) {
    producerCount = 0;
    producerCPS = 6666;
    refreshTotalProducerCPS();
    producerCost = 1000000;
}
