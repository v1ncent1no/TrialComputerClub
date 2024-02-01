#pragma once

#include <optional>
#include <string_view>

//<number of tables in the computer club>
//<start time> <end time>
//<the cost of an hour in the computer club>
//<event time 1> <event ID 1> <event body 1>
//<event time 2> <event id 2> <event body 2>
//...
//<event time N> <event id N> <event body N>
//
// --------------------------------------------------------------
//
//<data_input> ::= <tables> <time_period> <cost_per_hour> <events>
//<tables> ::= <number> '\n'
//<time_period> ::= <time> <colon> <time> '\n'
//<cost_per_hour> ::= <number> '\n'
//<events> ::= <event> | <event> <events> '\0'
//<event> ::= <time> <event_id> <event_body> '\n'
//<time> ::= <number>
//<event_id> ::= <number>
//<event_body> ::= <string>

//<number> ::= <digit> | <digit> <number>
//<digit> ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
//<string> ::= <char> | <char> <string>
//<char> ::= <letter> | <digit>
//<letter> ::= 'A' | 'B' | 'C' | ... | 'Z' | 'a' | 'b' | 'c' | ... | 'z'
//<space> ::= ' '
//<colon> ::= ':'
namespace parser {

enum TokenType {
    tok_number,
    tok_string,
    tok_space,
    tok_newline,
    tok_colon,
    tok_eof,
};

struct Token {
    TokenType type;
    std::optional<std::string_view> lexem{};
};

struct TokenizerMetadata {
    size_t line;
    size_t character;
};

class Tokenizer {
    const char *source;
    TokenizerMetadata metadata; // TODO: use metadata for gracefull error outout

    auto read_chunk(Token &token, bool (*condition)(char ch)) -> void;

public:
    Tokenizer(const char *source)
        : source(source), metadata{.line = 0, .character = 0} {}

    auto next(Token &token) -> bool;
};

} // namespace parser
