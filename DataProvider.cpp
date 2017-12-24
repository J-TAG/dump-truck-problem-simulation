/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "DataProvider.hpp"

#include <QList>

unsigned int DataProvider::currentClock = 0;
unsigned int DataProvider::pastClock = 0;

DataProvider::DataProvider()
{

}

short DataProvider::getRandomLoadingTime()
{
    QList<short> items;
    items.append(5);
    items.append(10);
    items.append(15);

    short high = 10;
    short low = 0;
    short randomDigit = qrand() % ((high + 1) - low) + low;
    short index = 0;

    switch (randomDigit) {
    case 1:case 2:case 3:
        index = 0;
        break;
    case 4:case 5:case 6:case 7:case 8:
        index = 1;
        break;
    case 9:case 0:
        index = 2;
        break;
    default:
        break;
    }
    return items.at(index);
}

short DataProvider::getRandomWeighingTime()
{
    QList<short> items;
    items.append(12);
    items.append(16);

    short high = 10;
    short low = 0;
    short randomDigit = qrand() % ((high + 1) - low) + low;
    short index = 0;

    switch (randomDigit) {
    case 1:case 2:case 3:case 4:case 5:case 6:case 7:
        index = 0;
        break;
    case 8:case 9:case 0:
        index = 1;
        break;
    default:
        break;
    }

    return items.at(index);
}

int DataProvider::getRandomTravelTime()
{
    QList<short> items;
    items.append(40);
    items.append(60);
    items.append(80);
    items.append(100);

    short high = 10;
    short low = 0;
    short randomDigit = qrand() % ((high + 1) - low) + low;
    short index = 0;

    switch (randomDigit) {
    case 1:case 2:case 3: case 4:
        index = 0;
        break;
    case 5:case 6:case 7:
        index = 1;
        break;
    case 8: case 9:
        index = 2;
        break;
    case 0:
        index = 3;
        break;
    default:
        break;
    }
    return items.at(index);
}

void DataProvider::updateClock(unsigned int newClock)
{
    DataProvider::pastClock = DataProvider::currentClock;
    DataProvider::currentClock = newClock;
}

unsigned int DataProvider::getClockTimePenalty()
{
    return DataProvider::currentClock - DataProvider::pastClock;
}

unsigned int DataProvider::getCurrentClock()
{
    return DataProvider::currentClock;
}

void DataProvider::clear()
{
    DataProvider::currentClock = 0;
    DataProvider::pastClock = 0;
}
