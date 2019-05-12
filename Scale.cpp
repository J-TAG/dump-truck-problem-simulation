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
        unsigned int time = uint(DataProvider::getRandomWeighingTime()) + DataProvider::getCurrentClock();
        Event *event = new Event(Event::EW, time, truck);
        FutureEventList::getInstance()->addEvent(event);
        return true;
    }

    return false;
}

bool Scale::canAddTruck()
{
    return !this->isBusy();
}

bool Scale::isBusy()
{
    return (this->scale != nullptr);
}

QString Scale::getCount() const
{
    short count = 0;

    if(this->scale != nullptr) {
        count++;
    }

    return QString::number(count);
}

void Scale::processEvents(WeighQueue &weighQueue)
{
    unsigned int timePenalty = DataProvider::getClockTimePenalty();

    // Update status of current item
    if(this->scale != nullptr) {
        auto futureList = FutureEventList::getInstance();
        Event* event = futureList->atTruck(this->scale->getIndex());
        if(event != nullptr) {
            if(event->getEventType() == Event::EW && event->getTime() == DataProvider::getCurrentClock()) {
                CumulativeStatistics::appendScaleBusyTime(timePenalty);
                // At this time, weighing is finished and we must add new event for ALQ and also clear scale
                auto time = uint(DataProvider::getRandomTravelTime()) + DataProvider::getCurrentClock();
                Event *alqEvent = new Event(Event::ALQ, time, event->getTruck());
                futureList->removeEvent(event);
                futureList->addEvent(alqEvent);
                this->release();
            }
        }
    }


    if(this->isBusy()) {
        CumulativeStatistics::appendScaleBusyTime(timePenalty);
    } else {
        // Check to see if we have items in scale queue
        DumpTruck *nextTruck = weighQueue.getNextTruck();
        if(nextTruck != nullptr) {
            this->addTruck(nextTruck);
        }
    }

}

void Scale::release()
{
    this->scale = nullptr;
}
