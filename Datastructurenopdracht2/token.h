//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018


#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <cmath>
#ifndef token_h
#define token_h

//klasse voor Token
class Token {
  public:

  //constructor.
  Token(std::string woord);
  //bepaalt ariteit.
  int arity();
        enum {
PLUS, MIN , NUM, VAR, MULT, EXP, DIV, SIN, COS, PI } type;
        union {
            char variable;
            double number;
        };
};

#endif
