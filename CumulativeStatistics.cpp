/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "CumulativeStatistics.hpp"

int CumulativeStatistics::busyTimeLoaders = 0;
int CumulativeStatistics::busyTimeScale = 0;


CumulativeStatistics::CumulativeStatistics()
{

}

void CumulativeStatistics::appendLoadersBusyTime(int time)
{
    CumulativeStatistics::busyTimeLoaders += time;
}

void CumulativeStatistics::appendScaleBusyTime(int time)
{
    CumulativeStatistics::busyTimeScale += time;
}

int CumulativeStatistics::getLoadersBusyTime()
{
    return CumulativeStatistics::busyTimeLoaders;
}

int CumulativeStatistics::getScaleBusyTime()
{
    return CumulativeStatistics::busyTimeScale;
}

void CumulativeStatistics::clear()
{
    CumulativeStatistics::busyTimeLoaders = 0;
    CumulativeStatistics::busyTimeScale = 0;
}
