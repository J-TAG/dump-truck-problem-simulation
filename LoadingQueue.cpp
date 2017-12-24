/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "DataProvider.hpp"
#include "FutureEventList.hpp"
#include "LoadingQueue.hpp"

LoadingQueue::LoadingQueue(QObject *parent) : Queue(parent)
{

}

void LoadingQueue::addTruck(DumpTruck *truck)
{
    Queue::addTruck(truck);
    truck->setState(DumpTruck::InLoaderQueue);
}

void LoadingQueue::processEvents(Event* nextEvent)
{
    // Handle arrived items from ALQ
    auto futureList = FutureEventList::getInstance();

    // Add arrived trucks to loading queue
    if(nextEvent->getEventType() == Event::ALQ && nextEvent->getTime() == DataProvider::getCurrentClock()) {
        this->addTruck(nextEvent->getTruck());
        futureList->removeEvent(nextEvent);
    }
}

