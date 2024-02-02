#include "timeutil.h"
#include <format>

// created my own time point class to simplify the logic, otherwise, using
// `<chrono>` types would loook messy
auto TimePoint::create(size_t hours, size_t minutes) -> TimePoint {
	if (hours >= 60 || minutes >= 60) {
		throw TimePointWrongFormat(
			std::format("supplied time point fomat is wrong"));
	}

	return TimePoint(hours, minutes);
}

auto TimePoint::reset(size_t hours, size_t minutes) -> void {
	if (hours >= 60 || minutes >= 60) {
		throw TimePointWrongFormat(
			std::format("supplied time point fomat is wrong"));
	}

	this->hours = hours;
	this->minutes = minutes;
}

constexpr auto TimePoint::operator<=(const TimePoint &other) -> bool {
	return raw_minutes <= other.raw_minutes;
}
constexpr auto TimePoint::operator>=(const TimePoint &other) -> bool {
	return raw_minutes >= other.raw_minutes;
}
constexpr auto TimePoint::operator<(const TimePoint &other) -> bool {
	return raw_minutes < other.raw_minutes;
}
constexpr auto TimePoint::operator>(const TimePoint &other) -> bool {
	return raw_minutes > other.raw_minutes;
}
constexpr auto TimePoint::operator==(const TimePoint &other) -> bool {
	return raw_minutes == other.raw_minutes;
}

constexpr auto TimePoint::get_hours() -> size_t { return hours; }
constexpr auto TimePoint::get_minutes() -> size_t { return minutes; }

auto TimeInterval::is_during_interval(TimePoint &time) -> bool {
	return time >= begin && time <= end;
}
