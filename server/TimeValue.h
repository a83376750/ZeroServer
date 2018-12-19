#pragma once
#include <ctime>
#include <string>

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

	static std::time_t GetTime();
	static std::string GetCurTimeStr();
	TimeValue();
	~TimeValue();
};

