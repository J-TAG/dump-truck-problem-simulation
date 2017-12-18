/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "WeighQueue.hpp"

WeighQueue::WeighQueue(QObject *parent) : Queue(parent)
{

}

void WeighQueue::addTruck(DumpTruck *truck)
{
    Queue::addTruck(truck);
    truck->setState(DumpTruck::InWeighQueue);
}

