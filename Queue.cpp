/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "Queue.hpp"

Queue::Queue(QObject *parent) : QObject(parent)
{

}

void Queue::addTruck(DumpTruck *truck)
{
    this->queue.enqueue(truck);
}

DumpTruck *Queue::getNextTruck()
{
    if(this->queue.isEmpty()) {
        // Queue is empty
        return nullptr;
    }

    return this->queue.dequeue();
}

QString Queue::getString() const
{
    if(this->queue.isEmpty()) {
        // Queue is empty
        return "";
    }

    QString strResult;
    foreach (auto truck, this->queue) {
        strResult += truck->getName() + ",";
    }

    return strResult;
}

QString Queue::getCount() const
{
    return QString::number(this->queue.count());
}
