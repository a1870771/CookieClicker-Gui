#include "timemachine.h"

timeMachine::timeMachine(QWidget* parent) :
    producer(parent) {
    producerCount = 0;
    producerCPS = 123456;
    refreshTotalProducerCPS();
    producerCost = 123456789;
}
