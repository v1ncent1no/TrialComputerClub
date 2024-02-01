#pragma once

#include <string_view>

namespace parser {

enum TokenType {
    time_point,
    integral,
    name,
};

struct Token {
    TokenType type;
    std::string_view lexem;
};

class Tokenizer {

public:
};

} // namespace parser
