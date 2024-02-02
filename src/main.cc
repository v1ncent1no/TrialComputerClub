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

auto main(int argc, char **argv) -> int {
    std::vector<Table> tables(10);

    if (argc < 2) {
        fprintf(stderr, "USAGE:\n%s [file name]\n", argv[0]);
        return EX_USAGE;
    }

    std::ifstream file{argv[1], std::ios::in};

    return 0;
}
