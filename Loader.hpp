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

#include <QObject>

class Loader : public QObject
{
    Q_OBJECT
public:
    explicit Loader(QObject *parent = nullptr);
    bool addTruck(DumpTruck *truck);
    bool canAddTruck();
    QString getCount() const;

signals:

public slots:
private:
    DumpTruck *loader1 = nullptr;
    DumpTruck *loader2 = nullptr;
};

#endif // LOADER_HPP
