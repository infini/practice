
#include "stdafx.h"
#include "stop_watch.h"


StopWatch::StopWatch()
{
	::QueryPerformanceFrequency( &m_perf_freq );
	start();
}

StopWatch::~StopWatch()
{
}

void	StopWatch::start()
{
	::QueryPerformanceCounter( &m_perf_start );
}

__int64	StopWatch::now() const
{
	LARGE_INTEGER	per_now;
	::QueryPerformanceCounter( &per_now );
	return ( ( ( per_now.QuadPart - m_perf_start.QuadPart ) * 1000 ) / m_perf_freq.QuadPart );
}

__int64	StopWatch::now_in_micro() const
{
	LARGE_INTEGER	per_now;
	::QueryPerformanceCounter( &per_now );
	return ( ( ( per_now.QuadPart - m_perf_start.QuadPart ) * 1000000 ) / m_perf_freq.QuadPart );
}
