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
#include "Loader.hpp"

Loader::Loader(QObject *parent) : QObject(parent)
{

}

bool Loader::addTruck(DumpTruck *truck)
{
    if(this->canAddTruck()) {
        if(this->loader1 == nullptr) {
            this->loader1 = truck;
        } else if(this->loader2 == nullptr) {
            this->loader2 = truck;
        } else {
            return false;
        }

        truck->setState(DumpTruck::Loading);
        Event *event = new Event(Event::EL, DataProvider::getRandomLoadingTime(), truck);
        FutureEventList::getInstance()->addEvent(event);

        return true;
    }

    return false;
}

bool Loader::canAddTruck()
{
    if(this->loader1 == nullptr || this->loader2 == nullptr) {
        return true;
    }
    return false;
}

QString Loader::getCount() const
{
    short count = 0;

    if(this->loader1 != nullptr) {
        count++;
    }

    if(this->loader2 != nullptr) {
        count++;
    }

    return QString::number(count);
}
