/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef LOADER_HPP
#define LOADER_HPP

#include "DumpTruck.hpp"
#include "LoadingQueue.hpp"
#include "WeighQueue.hpp"

#include <QObject>

class Loader : public QObject
{
    Q_OBJECT
public:
    explicit Loader(QObject *parent = nullptr);
    bool addTruck(DumpTruck *truck);
    bool canAddTruck();
    bool isLoader1Busy();
    bool isLoader2Busy();
    QString getCount() const;
    void processEvents(LoadingQueue &loadingQueue, WeighQueue &weighQueue);
    void releaseLoader1();
    void releaseLoader2();

signals:

public slots:
private:
    DumpTruck *loader1 = nullptr;
    DumpTruck *loader2 = nullptr;
};

#endif // LOADER_HPP
