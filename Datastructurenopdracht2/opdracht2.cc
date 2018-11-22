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

Node* root;

//bool isBinaryOperator() const;






int main() {


Tree S;
S.MakeTree("+ 2 + 2 4", root);
S.TreeSimplify(root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;
//S.DOT();


  return 0;
}
