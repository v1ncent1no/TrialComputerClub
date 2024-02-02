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
    if (*src > 0) {
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
                this->read_chunk(token, [](char ch) -> bool {
                    return isdigit(ch) || ch == '_' || ch == '-';
                });
            } else if (isalpha(curr)) {
                token.type = tok_string;
                this->read_chunk(token,
                                 [](char ch) -> bool { return isalnum(ch); });
            }
        }
    } else {
        token.type = tok_eof;
        return false;
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
