# Computer Club

TODO

# Task

TODO

# Desgin Choices

TODO

# Implementation Details

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
 <time_period> ::= <time> <colon> <time> '\n'
 <cost_per_hour> ::= <number> '\n'
 <events> ::= <event> | <event> <events> '\0'
 <event> ::= <time> <event_id> <event_body> '\n'
 <time> ::= <number>
 <event_id> ::= <number>
 <event_body> ::= <string> <number> <string> '\n' | <string> <number> <string> <number> '\n'

 <number> ::= <digit> | <digit> <number>
 <digit> ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
 <string> ::= <char> | <char> <string>
 <char> ::= <letter> | <digit>
 <letter> ::= 'a' | 'b' | 'c' | ... | 'z'
 <space> ::= ' '
 <colon> ::= ':'
```
