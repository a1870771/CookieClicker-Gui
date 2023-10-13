#include "shipment.h"

shipment::shipment(QWidget* parent)
    :
    producer(parent) {
    producerCount = 0;
    producerCPS = 100;
    refreshTotalProducerCPS();
    producerCost = 7000;
}
