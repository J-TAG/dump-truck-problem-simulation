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
#include "FutureEventList.hpp"
#include "Scale.hpp"

Scale::Scale(QObject *parent) : QObject(parent)
{

}

bool Scale::addTruck(DumpTruck *truck)
{
    if(this->canAddTruck()) {
        if(this->scale == nullptr) {
            this->scale = truck;
        } else {
            return false;
        }
        truck->setState(DumpTruck::Weighing);
        Event *event = new Event(Event::EW, DataProvider::getRandomWaitingTime(), truck);
        FutureEventList::getInstance()->addEvent(event);
        return true;
    }

    return false;
}

bool Scale::canAddTruck()
{
    if(this->scale == nullptr) {
        return true;
    }
    return false;
}

QString Scale::getCount() const
{
    short count = 0;

    if(this->scale != nullptr) {
        count++;
    }

    return QString::number(count);
}
