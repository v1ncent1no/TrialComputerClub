#include <compare>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include <algorithm>

#include <fstream>

#if defined(__unix__)
#include <sysexits.h>
#else
#define EX_USAGE 64   /* command line usage error */
#define EX_NOINPUT 66 /* cannot open input */
#define EX_IOERR 74   /* input/output error */
#endif

#include <chrono>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

enum DataError : size_t {
    client_already_inside,    // "YouShallNotPass"
    club_is_closed,           // "NotOpenYet"
    place_is_busy,            // "PlaceIsBusy"
    client_unknown,           // "ClientUnknown"
    waiting_while_seats_free, // "ICanWaitNoLonger!"
};

const char *error_str[] = {
    "YouShallNotPass", "NotOpenYet",        "PlaceIsBusy",
    "ClientUnknown",   "ICanWaitNoLonger!",
};

struct TimePointWrongFormat : public std::runtime_error {
    TimePointWrongFormat(const std::string &msg) : std::runtime_error(msg) {}
};

class TimePoint {
    size_t hours, minutes;
    size_t raw_minutes; // chached value

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

    auto operator<=>(const TimePoint &other) {
        return raw_minutes <=> other.raw_minutes;
    }
};

struct TimeInterval {
    TimePoint begin;
    TimePoint end;

    auto is_during_interval(TimePoint time) -> bool {
        return time >= begin && time <= end;
    }
};

class Table {
    size_t id;
    std::queue<std::string> client_queue;

public:
};

auto main(int argc, char **argv) -> int {
    std::vector<Table> tables;
    // TimeInterval openDuration;

    if (argc < 2) {
        fprintf(stderr, "USAGE:\n%s [file name]\n", argv[0]);
        return EX_USAGE;
    }

    std::ifstream file{argv[1], std::ios::in};

    return 0;
}
