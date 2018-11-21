#ifndef token_h
#define token_h

#include <string>

class Token {
public:

  Token(std::string woord);
  int arity();
        enum {
PLUS, MIN , NUM, VAR, MULT,DIV , SIN, COS, PI } type;
        union {
            char variable;
            double number;
        };
};

Token::Token(std::string woord) {
  double value;
  char letter;
  if (woord == "+") {
    type = PLUS;
    variable = '+'
  }
  else if (woord == "-")
    type = MIN;
  else if (woord == "*")
    type = MULT;
  else if (woord == "/")
    type = DIV;
  else if (woord == "sin")
    type = SIN;
  else if (woord == "cos")
    type = COS;
  else if (woord == "pi")
    type = PI;
//  else if (std::stringstream(woord) >> letter) {
//    type = VAR;
//    variable = letter;
//}

  else if (std::stringstream(woord) >> value) {
    type = NUM;
    number = value;
  }
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
    case PI:
  return 0;

    case SIN:
    case COS:
  return 1;
  }

}

#endif
