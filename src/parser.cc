#include "parser.h"

#include <ctype.h>

namespace parser {
// TODO: rewrite the explanation in the morning after you wake you
//
// Tokenizer::next was design with idea that it could be used as lazy iterator
// which might even reuse the same memory of one Token. This is why why
// initialize the lexem part to {}, where we don't have any, so that it wouldn't
// mess with external logic in some way
auto Tokenizer::next(Token &token) -> bool {
    if (*source > 0) {
        char ch = *source++;

        switch (ch) {
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
            if (isdigit(ch)) {
                token.type = tok_number;
                this->read_chunk(token,
                                 [](char ch) -> bool { return isdigit(ch); });
            } else if (isalpha(ch)) {
                token.type == tok_string;
                this->read_chunk(token,
                                 [](char ch) -> bool { return isalnum(ch); });
            }
        }
    } else {
        token.type = tok_eof;
        return false;
    }

    return true;
}

auto Tokenizer::read_chunk(Token &token, bool (*condition)(char ch)) -> void {
    const char *begin = source - 1;

    while (*source > 0 && condition(*source))
        source++;

    token.lexem = {begin, source};
}
} // namespace parser
