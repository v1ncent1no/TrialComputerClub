#include <stdexcept>

struct TimePointWrongFormat : public std::runtime_error {
    TimePointWrongFormat(const std::string &msg) : std::runtime_error(msg) {}
};

class TimePoint {
    size_t hours, minutes;
    size_t raw_minutes;

    // constructor made private because user might attempt to create an object
    // with wrong values for hours and minutes
    TimePoint(size_t hours, size_t minutes)
        : raw_minutes(hours * 60 + minutes), hours(hours), minutes(minutes) {}

public:
    static auto create(size_t hours, size_t minutes) -> TimePoint;

    auto reset(size_t hours, size_t minutes) -> void;

    constexpr auto operator<=(const TimePoint &other) -> bool;
    constexpr auto operator>=(const TimePoint &other) -> bool;
    constexpr auto operator<(const TimePoint &other) -> bool;
    constexpr auto operator>(const TimePoint &other) -> bool;
    constexpr auto operator==(const TimePoint &other) -> bool;

    constexpr auto get_hours() -> size_t;
    constexpr auto get_minutes() -> size_t;
};

struct TimeInterval {
    TimePoint begin;
    TimePoint end;

    auto is_during_interval(TimePoint &time) -> bool;
};
