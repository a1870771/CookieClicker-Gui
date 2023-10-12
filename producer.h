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

    producer(QWidget * parent = Q_NULLPTR);

    int getProducerCount() const;
    void incProducerCount();

    float getTotalProducerCPS() const;
    void refreshTotalProducerCPS();

    float getProducerCPS() const; // Varies between each object
    void setProducerCPS(float CPS); // Setter only for testing

    virtual long getProducerCost() const; // Cost will be found using an exponential function
    void setProducerCost(int cost); // Setter only for testing

    void buyProducer(int cookies);
    ~producer();

signals:
    void clicked();
};

#endif // PRODUCER_H
