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
    static short getRandomWeighingTime();
    static int getRandomTravelTime();
    static void updateClock(unsigned int newClock);
    static unsigned int getClockTimePenalty();
    static unsigned int getCurrentClock();

private:
    static unsigned int currentClock;
    static unsigned int pastClock;
};

#endif // DATAPROVIDER_HPP
