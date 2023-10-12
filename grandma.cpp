#include "grandma.h"
#include "producer.h"

#include <QLabel>
#include <QWidget>


grandma::grandma(QWidget* parent) :
    producer(parent) {
    producerCount = 0;
    producerCPS = 1;
    refreshTotalProducerCPS();
    producerCost = 10;
}
