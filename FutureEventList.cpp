/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "FutureEventList.hpp"

FutureEventList::FutureEventList()
{

}

FutureEventList *FutureEventList::getInstance()
{
    static FutureEventList *instance = new FutureEventList();
    return instance;
}

void FutureEventList::addEvent(Event *event)
{
    this->lstEvents.append(event);
}

void FutureEventList::removeEvent(Event *event)
{
    if(this->lstEvents.isEmpty()) {
        return;
    }

    this->lstEvents.removeOne(event);
}

void FutureEventList::clear()
{
    this->lstEvents.clear();
}

QString FutureEventList::getString() const
{
    QString strResult;

    foreach (auto event, this->lstEvents) {
        strResult += "(" + event->getTypeString() + "," + event->getTimeString() + "," + event->getTruck()->getName() + "), ";
    }

    return strResult;
}

Event *FutureEventList::getNextEvent()
{
    if(this->lstEvents.isEmpty()) {
        return nullptr;
    }

    int pastTime = this->lstEvents.first()->getTime();
    int index = 0;

    for (int i = 0; i < this->lstEvents.size(); ++i) {
        int eventTime = this->lstEvents.at(i)->getTime();

        if(eventTime < pastTime) {
            index = i;
        }

        pastTime = eventTime;
    }

    return this->lstEvents.at(index);
}

Event *FutureEventList::atTruck(int truckIndex) const
{
    if(this->lstEvents.isEmpty()) {
        return nullptr;
    }

    for (int i = 0; i < this->lstEvents.size(); ++i) {
        int index = this->lstEvents.at(i)->getTruck()->getIndex();

        if(index == truckIndex) {
            return this->lstEvents.at(i);
        }

    }

    return nullptr;
}
