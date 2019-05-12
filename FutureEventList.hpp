/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef FUTUREEVENTLIST_HPP
#define FUTUREEVENTLIST_HPP

#include "Event.hpp"

class FutureEventList
{
public:
    static FutureEventList *getInstance();
    void addEvent(Event *event);
    void removeEvent(Event *event);
    void clear();
    QString getString() const;
    Event* getNextEvent();
    Event* atTruck(unsigned int truckIndex) const;

signals:

public slots:
private:
    FutureEventList();
    QList<Event*> lstEvents;
};

#endif // FUTUREEVENTLIST_HPP
