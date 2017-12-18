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
