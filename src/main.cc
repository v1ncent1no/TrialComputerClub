#include <fstream>
#include <iostream>

#include <queue>
#include <string>
#include <vector>

#include <chrono>

#if defined(__unix__)
#include <sysexits.h>
#else
#define EX_USAGE 64   /* command line usage error */
#define EX_NOINPUT 66 /* cannot open input */
#define EX_IOERR 74   /* input/output error */
#endif

#include "timeutil.h"

typedef unsigned int uint;

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

class Table {
    size_t id;
    std::queue<std::string> client_queue;

public:
};

// TODO: Implememta a binary that keeps income and outcome events sorted by time
// point
enum EventType {
    event_client_came,
    event_client_takes_seat,
    event_client_leaves,
};

struct Event {
    TimePoint time;
    EventType type;
    std::string_view client_name;

    std::optional<int> table_index;
};

class IOEvents {
    Event value;

    IOEvents *earlier;
    IOEvents *further;

public:
};

class State {
    uint table_count;
    TimeInterval work_hours;
    double cost_per_hour;

    IOEvents events;

public:
};

auto main(int argc, char **argv) -> int {
    std::vector<Table> tables{};

    if (argc < 2) {
        fprintf(stderr, "USAGE:\n%s [file name]\n", argv[0]);
        return EX_USAGE;
    }

    std::ifstream file{argv[1], std::ios::in};
    // Check the lexer for correctness

    return 0;
}
