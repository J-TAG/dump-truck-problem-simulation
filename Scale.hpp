/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef SCALE_HPP
#define SCALE_HPP

#include "DumpTruck.hpp"
#include "WeighQueue.hpp"

#include <QObject>

class Scale : public QObject
{
    Q_OBJECT
public:
    explicit Scale(QObject *parent = nullptr);
    bool addTruck(DumpTruck *truck);
    bool canAddTruck();
    bool isBusy();
    QString getCount() const;
    void processEvents(WeighQueue &weighQueue);
    void release();

signals:

public slots:
private:
    DumpTruck *scale= nullptr;
};

#endif // SCALE_HPP
