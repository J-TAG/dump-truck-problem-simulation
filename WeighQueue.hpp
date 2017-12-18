/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef WEIGHQUEUE_HPP
#define WEIGHQUEUE_HPP

#include "DumpTruck.hpp"
#include "Queue.hpp"

#include <QObject>

class WeighQueue : public Queue
{
    Q_OBJECT
public:
    explicit WeighQueue(QObject *parent = nullptr);
    void addTruck(DumpTruck *truck);

signals:

public slots:
};

#endif // WEIGHQUEUE_HPP
