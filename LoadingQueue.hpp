/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef LOADINGQUEUE_HPP
#define LOADINGQUEUE_HPP

#include "DumpTruck.hpp"
#include "Queue.hpp"

#include <QObject>
#include <QQueue>

class LoadingQueue : public Queue
{
    Q_OBJECT
public:
    explicit LoadingQueue(QObject *parent = nullptr);
    void addTruck(DumpTruck *truck);

signals:

public slots:
};

#endif // LOADINGQUEUE_HPP
