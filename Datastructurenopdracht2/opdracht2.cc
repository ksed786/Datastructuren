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
int a, b, c;
//bool isBinaryOperator() const;

int main() {
a = 1;
b = 2;
c = 1;


Tree S;
<<<<<<< HEAD
S.MakeTree("* 2 b", root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;
S.TreeSimplify(root);
S.TreeSimplify(root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;

=======

S.MakeTree("+ + b 5 5", root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;
//S.DOT(root, a, b, c);
S.TreeSimplify(root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;
>>>>>>> Olivier


  return 0;
}
