#include "alchemylab.h"

alchemyLab::alchemyLab(QWidget* parent) :
    producer(parent) {
    producerCount = 0;
    producerCPS = 500;
    refreshTotalProducerCPS();
    producerCost = 50000;
}
