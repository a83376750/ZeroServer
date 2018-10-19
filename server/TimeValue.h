#pragma once
#include <ctime>

class TimeValue
{
public:
	static const int USECS;
	static const int SECOND;
	static const int MINUTE;
	static const int HOUR;
	static const int DAY;
	static const int WEEK;

public:
	static const TimeValue ZERO;

	std::time_t getTime();
	TimeValue();
	~TimeValue();
};

