#ifndef token_h
#define token_h

#include <string>

class Token {
public:

  Token(std::string woord);
  int arity();
        enum {
PLUS, MIN , NUM, VAR, MULT, DIV } type;
        union {
            char variable;
            double number;
        };
};

Token::Token(std::string woord) {
  double value;
  if (woord == "+")
    type = PLUS;
  else if (woord == "-")
    type = MIN;
  else if (woord == "*")
    type = MULT;
  else if (woord == "/")
    type = DIV;
  else if (std::stringstream(woord) >> value) {
    type = NUM;
    number = value;
  }
  //return token;
}

int Token::arity() {
  switch (type) {
    case PLUS:
    case MIN:
    case MULT:
    case DIV:
   return 2;

    case NUM:
    case VAR:
  return 0;
  }

}

#endif
