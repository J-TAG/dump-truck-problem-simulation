/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "DumpTruck.hpp"

DumpTruck::DumpTruck(unsigned int index, QObject *parent) : QObject(parent), index(index)
{

}

void DumpTruck::setState(DumpTruck::State state)
{
    this->state = state;
}

QString DumpTruck::getName() const
{
    return "DT" + QString::number(this->index);
}

unsigned int DumpTruck::getIndex() const
{
    return this->index;
}

DumpTruck::State DumpTruck::getState() const
{
    return this->state;
}
