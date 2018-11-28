//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

#include "token.h"
#include <string>
#include <cstring>

//constructor
Token::Token(std::string woord) {
  double value;
  char letter;
  if (woord == "+") {
    type = PLUS;
    variable = '+';
  }
  else if (woord == "-") {
    type = MIN;
    variable = '-';
  }
  else if (woord == "*"){
    type = MULT;
    variable = '*';
  }
  else if (woord == "/") {
    type = DIV;
    variable = '/';
  }
  else if (woord == "^") {
    type = EXP;
    variable = '^';
  }
  else if (woord == "sin")
    type = SIN;
  else if (woord == "cos")
    type = COS;
  else if (woord == "pi") {
    type = PI;
    number = 3.14159265359;
  }
  else if (std::stringstream(woord) >> value) {
    type = NUM;
    number = value;
  }

  else {
    letter = woord[0];
    type = VAR;
    variable = letter;
  }
}

int Token::arity() {
  switch (type) {
    case PLUS:
    case MIN:
    case MULT:
    case DIV:
    case EXP:
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
