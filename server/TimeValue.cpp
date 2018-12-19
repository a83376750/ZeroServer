#include "TimeValue.h"
#include <chrono>
#include <iomanip>
#include <time.h>
#include <sstream>

const TimeValue TimeValue::ZERO;

const int TimeValue::USECS = 1000000;
const int TimeValue::SECOND = 1;
const int TimeValue::MINUTE = 60;
const int TimeValue::HOUR = 60 * TimeValue::MINUTE;
const int TimeValue::DAY = 24 * TimeValue::HOUR;
const int TimeValue::WEEK = 7 * TimeValue::DAY;

TimeValue::TimeValue()
{
}


TimeValue::~TimeValue()
{
}

std::time_t TimeValue::GetTime()
{
	using namespace std::chrono;
	time_point<system_clock, seconds> tp = time_point_cast<seconds>(system_clock::now());
	auto tmp = duration_cast<seconds>(tp.time_since_epoch());
	return tmp.count();
}

std::string TimeValue::GetCurTimeStr()
{
	auto time_now = std::chrono::system_clock::now();
	auto t = std::chrono::system_clock::to_time_t(time_now);
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());
	auto ms_part = duration_in_ms - std::chrono::duration_cast<std::chrono::seconds>(duration_in_ms);
	
	tm time;
	localtime_s(&time, &t);
	std::stringstream ss;
	ss << std::put_time(&time, "%Y-%m-%d %H.%M.%S") << ms_part.count();
	return ss.str();
}
