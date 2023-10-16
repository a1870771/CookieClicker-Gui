#ifndef PRODUCER_H
#define PRODUCER_H

#include <QLabel>
#include <QWidget>

class producer : public QLabel
{

    Q_OBJECT


protected:
    int producerCount;
    float producerCPS;
    float totalProducerCPS;
    long producerCost;
    void mousePressEvent(QMouseEvent* Event);

public:

    producer(QWidget * parent = Q_NULLPTR);     //constructor calls QLabel constructor and creates QObject on ui

    int getProducerCount() const;       //returns number of relevant producers in current game
    void setProducerCount(int c);       //sets number of relevant producers to c
    void incProducerCount();            //increments producercount - used in buy functions

    float getTotalProducerCPS() const;  //returns total cps (producer count * individual cps)
    void refreshTotalProducerCPS();     //sets total cps to (producercount * individual cps) - used when producer count is updated

    float getProducerCPS() const;       //varies between each subclass, returns cps for one relevant producer
    void setProducerCPS(float CPS); // Setter only for testing

    virtual long getProducerCost() const;   // returns cost of relevant producer
    void setProducerCost(int cost); // Setter only for testing

    void buyProducer(int cookies);      //called when one of teh buy slots in cookieclicker is called, increments producercount and adjusts cookie count accordingly
    ~producer();

signals:
    void clicked();     //called when producer overlay is clicked, by extend executes buy function
};

#endif // PRODUCER_H
