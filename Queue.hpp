/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "DumpTruck.hpp"

#include <QObject>
#include <QQueue>

class Queue : public QObject
{
    Q_OBJECT
public:
    explicit Queue(QObject *parent = nullptr);
    void addTruck(DumpTruck *truck);
    DumpTruck *getNextTruck();
    QString getString() const;
    QString getCount() const;

signals:

public slots:
protected:
    QQueue<DumpTruck*> queue;
};

#endif // QUEUE_HPP
