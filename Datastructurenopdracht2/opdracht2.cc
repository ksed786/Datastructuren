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
int a, b;
//bool isBinaryOperator() const;






int main() {
a = 1;
b = 2;


Tree S;
<<<<<<< HEAD
S.MakeTree("+ + 2 5 + 2 5", root);
=======
S.MakeTree("cos 5", root);
S.TreeSimplify(root);
>>>>>>> Kousar
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;
S.DOT(root, a, b);
S.TreeSimplify(root);


  return 0;
}
