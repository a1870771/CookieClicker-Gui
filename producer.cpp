#include "producer.h"
#include "info.h"
//int producerCount;
//float producerCPS;
//float totalProducerCPS;
//long producerCost;

int producer::getProducerCount() const{
    return producerCount;
}
void producer::incProducerCount(){
    producerCount++;
}

float producer::getTotalProducerCPS() const{
    return totalProducerCPS;
}
void producer::refreshTotalProducerCPS(){
    totalProducerCPS = producerCount * producerCPS;
}

float producer::getProducerCPS() const{
    return producerCPS;
}
void producer::setProducerCPS(float CPS){
    producerCPS=CPS;
}


long producer::getProducerCost() const{
    return producerCost;
}
void producer::setProducerCost(int cost){
    producerCost=cost;
}
void producer::buyProducer(int cookies){
    if(cookies >= getProducerCost()){
        incProducerCount();
        refreshTotalProducerCPS();
    }
}

producer::~producer() {}

void producer::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

producer::producer(QWidget* parent)
    : QLabel(parent) {

}
