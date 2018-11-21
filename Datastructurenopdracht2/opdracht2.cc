//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <istream>
#include "token.h"
#include "node.h"
#include "tree.h"
//#include <stack>


//bool isBinaryOperator() const;






int main() {


Tree S;
S.MakeTree("+ 5 * 6 7");
S.PreOrder();
//root->DOT();


  return 0;
}
