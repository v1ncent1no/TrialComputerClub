#include "timeutil.h"
#include <format>

// created my own time point class to simplify the logic, otherwise, using
// `<chrono>` types would loook messy
class TimePoint {
    size_t hours, minutes;
    size_t raw_minutes;

    // constructor made private because user might attempt to create an object
    // with wrong values for hours and minutes
    TimePoint(size_t hours, size_t minutes)
        : raw_minutes(hours * 60 + minutes), hours(hours), minutes(minutes) {}

public:
    static auto create(size_t hours, size_t minutes) -> TimePoint {
        if (hours >= 60 || minutes >= 60) {
            throw TimePointWrongFormat(
                std::format("supplied time point fomat is wrong"));
        }

        return TimePoint(hours, minutes);
    }

    auto reset(size_t hours, size_t minutes) -> void {
        if (hours >= 60 || minutes >= 60) {
            throw TimePointWrongFormat(
                std::format("supplied time point fomat is wrong"));
        }

        this->hours = hours;
        this->minutes = minutes;
    }

    constexpr auto operator<=(const TimePoint &other) -> bool {
        return raw_minutes <= other.raw_minutes;
    }
    constexpr auto operator>=(const TimePoint &other) -> bool {
        return raw_minutes >= other.raw_minutes;
    }
    constexpr auto operator<(const TimePoint &other) -> bool {
        return raw_minutes < other.raw_minutes;
    }
    constexpr auto operator>(const TimePoint &other) -> bool {
        return raw_minutes > other.raw_minutes;
    }
    constexpr auto operator==(const TimePoint &other) -> bool {
        return raw_minutes == other.raw_minutes;
    }

    constexpr auto get_hours() -> size_t { return hours; }
    constexpr auto get_minutes() -> size_t { return minutes; }
};

struct TimeInterval {
    TimePoint begin;
    TimePoint end;

    auto is_during_interval(TimePoint &time) -> bool {
        return time >= begin && time <= end;
    }
};
