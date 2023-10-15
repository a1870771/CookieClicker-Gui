#include "clicker.h"

clicker::clicker(QWidget *parent):
    producer(parent) {
    producerCount = 0;
    producerCPS = 0;
    refreshTotalProducerCPS();
    producerCost = 15;
}
