#include "mine.h"

mine::mine(QWidget *parent) :
    producer(parent) {
    producerCount = 0;
    producerCPS = 20;
    refreshTotalProducerCPS();
    producerCost = 500;
 }
