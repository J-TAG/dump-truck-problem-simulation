/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef EVENT_HPP
#define EVENT_HPP

#include "DumpTruck.hpp"

#include <QObject>

class Event : public QObject
{
    Q_OBJECT
public:
    enum Type {
        None, ALQ, EL, EW
    };
    explicit Event(Type eventType, short time, DumpTruck *truck, QObject *parent = nullptr);
    QString getTypeString() const;
    int getTime() const;
    QString getTimeString() const;
    DumpTruck *getTruck();

signals:

public slots:
private:
    Type eventType = None;
    short time = 0;
    DumpTruck *truck = nullptr;
};

#endif // EVENT_HPP
