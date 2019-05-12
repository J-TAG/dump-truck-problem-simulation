/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef CUMULATIVESTATISTICS_HPP
#define CUMULATIVESTATISTICS_HPP


class CumulativeStatistics
{
public:
    CumulativeStatistics();
    static void appendLoadersBusyTime(unsigned int time);
    static void appendScaleBusyTime(unsigned int time);
    static unsigned int getLoadersBusyTime();
    static unsigned int getScaleBusyTime();
    static void clear();

private:
    static unsigned int busyTimeLoaders;
    static unsigned int busyTimeScale;
};

#endif // CUMULATIVESTATISTICS_HPP
