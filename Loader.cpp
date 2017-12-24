/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "CumulativeStatistics.hpp"
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

        short time = DataProvider::getRandomLoadingTime() + DataProvider::getCurrentClock();
        Event *event = new Event(Event::EL, time, truck);
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

bool Loader::isLoader1Busy()
{
    return (this->loader1 != nullptr);
}

bool Loader::isLoader2Busy()
{
    return (this->loader2 != nullptr);
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

void Loader::processEvents(LoadingQueue &loadingQueue, WeighQueue &weighQueue)
{
    // Update status of current items
    if(this->loader1 != nullptr) {
        auto futureList = FutureEventList::getInstance();
        Event* event = futureList->atTruck(this->loader1->getIndex());
        if(event != nullptr) {
            if(event->getEventType() == Event::EL && event->getTime() == DataProvider::getCurrentClock()) {
                // At this time, loading is finished and we must add truck to weighing queue and also clear loader
                weighQueue.addTruck(this->loader1);
                futureList->removeEvent(event);
                this->releaseLoader1();
            }
        }
    }

    if(this->loader2 != nullptr) {
        auto futureList = FutureEventList::getInstance();
        Event* event = futureList->atTruck(this->loader2->getIndex());
        if(event != nullptr) {
            if(event->getEventType() == Event::EL && event->getTime() == DataProvider::getCurrentClock()) {
                // At this time, loading is finished and we must add truck to weighing queue and also clear loader
                weighQueue.addTruck(this->loader2);
                futureList->removeEvent(event);
                this->releaseLoader2();
            }
        }
    }

    unsigned int timePenalty = DataProvider::getClockTimePenalty();

    if(this->isLoader1Busy()) {
        CumulativeStatistics::appendLoadersBusyTime(timePenalty);
    } else {
        // Check to see if we have items in loader queue
        DumpTruck *nextTruck = loadingQueue.getNextTruck();
        if(nextTruck != nullptr) {
            this->addTruck(nextTruck);
        }
    }

    if(this->isLoader2Busy()) {
        CumulativeStatistics::appendLoadersBusyTime(timePenalty);
    } else {
        // Check to see if we have items in loader queue
        DumpTruck *nextTruck = loadingQueue.getNextTruck();
        if(nextTruck != nullptr) {
            this->addTruck(nextTruck);
        }
    }
}

void Loader::releaseLoader1()
{
    this->loader1 = nullptr;
}

void Loader::releaseLoader2()
{
    this->loader2 = nullptr;
}
