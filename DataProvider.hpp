/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef DATAPROVIDER_HPP
#define DATAPROVIDER_HPP


class DataProvider
{
public:
    DataProvider();
    static short getRandomLoadingTime();
    static short getRandomWaitingTime();

    static unsigned int currntClock;
};

#endif // DATAPROVIDER_HPP
