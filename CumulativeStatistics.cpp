/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "CumulativeStatistics.hpp"

unsigned int CumulativeStatistics::busyTimeLoaders = 0;
unsigned int CumulativeStatistics::busyTimeScale = 0;


CumulativeStatistics::CumulativeStatistics()
{

}

void CumulativeStatistics::appendLoadersBusyTime(unsigned int time)
{
    CumulativeStatistics::busyTimeLoaders += time;
}

void CumulativeStatistics::appendScaleBusyTime(unsigned int time)
{
    CumulativeStatistics::busyTimeScale += time;
}

unsigned int CumulativeStatistics::getLoadersBusyTime()
{
    return CumulativeStatistics::busyTimeLoaders;
}

unsigned int CumulativeStatistics::getScaleBusyTime()
{
    return CumulativeStatistics::busyTimeScale;
}

void CumulativeStatistics::clear()
{
    CumulativeStatistics::busyTimeLoaders = 0;
    CumulativeStatistics::busyTimeScale = 0;
}
