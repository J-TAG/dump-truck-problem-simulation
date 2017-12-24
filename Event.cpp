/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "DataProvider.hpp"
#include "Event.hpp"

Event::Event(Type eventType, unsigned int time, DumpTruck *truck, QObject *parent) : QObject(parent), eventType(eventType), time(time), truck(truck)
{

}

Event::Type Event::getEventType() const
{
    return this->eventType;
}

QString Event::getTypeString() const
{
    QString type;

    switch (this->eventType) {
    case ALQ:
        type = "ALQ";
        break;
    case EL:
        type = "EL";
        break;
    case EW:
        type = "EW";
        break;
    default:
        type = "None";
        break;
    }

    return type;
}

QString Event::getTimeString() const
{
    return QString::number(this->getTime());
}

DumpTruck *Event::getTruck()
{
    return this->truck;
}

unsigned int Event::getTime() const
{
    return this->time;
}
