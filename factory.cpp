#include "factory.h"

factory::factory(QWidget *parent) :
    producer(parent){
    producerCount = 0;
    producerCPS = 50;
    refreshTotalProducerCPS();
    producerCost = 2000;
}
