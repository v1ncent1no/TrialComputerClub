#include "parser.h"

#include <cctype>

namespace parser {

auto is_allowed_char(char ch) -> bool {
    return std::isalpha(ch) || ch == '_' || ch == '-';
}
auto is_digit_wrapper(char ch) -> bool { return isdigit(ch); }

// Tokenizer::next was designed for it to be used as lazy iterator which might
// reuse the same memory of one Token. This is why it initializes the lexem part
// to {}, where we don't need to keep ot, so that it wouldn't mess up external
// logic in some way
auto Tokenizer::next(Token &token) -> bool {
    if (*src <= 0) {
        token.type = tok_eof;
        return false;
    }

    const char curr = *src;

    switch (curr) {
    case ':':
        token.type = tok_colon;
        token.lexem = {};
        break;
    // case '\t':
    case ' ':
        token.type = tok_space;
        token.lexem = {};
        break;
    case '\n':
        token.type = tok_newline;
        token.lexem = {};
        break;
    default:
        if (isdigit(curr)) {
            token.type = tok_number;
            read_chunk(token, is_digit_wrapper);
        } else if (is_allowed_char(curr)) {
            token.type = tok_string;
            read_chunk(token, is_allowed_char);
        } else {
            // TODO: handle unsupported character
        }
    }
    src++;

    return true;
}

auto Tokenizer::read_chunk(Token &token, bool (*condition)(char ch)) -> void {
    const char *begin = src;

    // take next character if it's not eof, '\0', or if it satisfies `condition`
    // TODO: justify why pointer arithmetic is used instead of std::count_if
    while (*src > 0 && condition(src[1]))
        src++;

    token.lexem = {begin, src};
}
} // namespace parser
