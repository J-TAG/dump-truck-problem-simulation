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
    static void appendLoadersBusyTime(int time);
    static void appendScaleBusyTime(int time);
    static int getLoadersBusyTime();
    static int getScaleBusyTime();
    static void clear();

private:
    static int busyTimeLoaders;
    static int busyTimeScale;
};

#endif // CUMULATIVESTATISTICS_HPP
