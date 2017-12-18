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

unsigned int DataProvider::currntClock = 0;

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

short DataProvider::getRandomWaitingTime()
{
    QList<short> items;
    items.append(12);
    items.append(16);

    short high = 1;
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
