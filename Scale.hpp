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

#include <QObject>

class Scale : public QObject
{
    Q_OBJECT
public:
    explicit Scale(QObject *parent = nullptr);
    bool addTruck(DumpTruck *truck);
    bool canAddTruck();
    QString getCount() const;

signals:

public slots:
private:
    DumpTruck *scale= nullptr;
};

#endif // SCALE_HPP
