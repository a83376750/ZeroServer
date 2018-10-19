#include "TimeValue.h"
#include <chrono>

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

std::time_t TimeValue::getTime()
{
	using namespace std::chrono;
	time_point<system_clock, milliseconds> tp = time_point_cast<milliseconds>(system_clock::now());
	auto tmp = duration_cast<milliseconds>(tp.time_since_epoch());
	return tmp.count();
}