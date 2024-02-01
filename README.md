## Input Data Format:
```
  <number of tables in the computer club>
  <start time> <end time>
  <the cost of an hour in the computer club>
  <event time 1> <event ID 1> <event body 1>
  <event time 2> <event id 2> <event body 2>
  ...
  <event time N> <event id N> <event body N>
````

### Translated to BNF

```
 <data_input> ::= <tables> <time_period> <cost_per_hour> <events>
 <tables> ::= <number> '\n'
 <time_period> ::= <time> <time> '\n'
 <cost_per_hour> ::= <number> '\n'
 <events> ::= <event> | <event> <events>
 <event> ::= <time> <event_id> <event_body> '\n'
 <time> ::= <number>
 <event_id> ::= <number>
 <event_body> ::= <string>

 <number> ::= <digit> | <digit> <number>
 <digit> ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
 <string> ::= <char> | <char> <string>
 <char> ::= <letter> | <digit> | <space> | <punctuation> | <symbol>
 <letter> ::= 'A' | 'B' | 'C' | ... | 'Z' | 'a' | 'b' | 'c' | ... | 'z'
 <space> ::= ' '
 <punctuation> ::= '.' | ',' | ';' | ':' | '!' | '?' | '-' | '_' | '"' | '''
 <symbol> ::= '@' | '#' | '$' | '%' | '^' | '&' | '*' | '(' | ')' | '+' |
              '=' | '<' | '>' | '[' | ']' | '{' | '}' | '|' | '\' | '/'
```
