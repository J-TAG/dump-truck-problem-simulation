/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "LoadingQueue.hpp"

LoadingQueue::LoadingQueue(QObject *parent) : Queue(parent)
{

}

void LoadingQueue::addTruck(DumpTruck *truck)
{
    Queue::addTruck(truck);
    truck->setState(DumpTruck::InLoaderQueue);
}

