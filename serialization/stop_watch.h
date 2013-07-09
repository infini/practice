
#pragma once


class StopWatch
{
public:
	StopWatch();
	~StopWatch();

	void	start();
	__int64	now() const;
	__int64	now_in_micro() const;


private:
	LARGE_INTEGER	m_perf_freq;
	LARGE_INTEGER	m_perf_start;
};
