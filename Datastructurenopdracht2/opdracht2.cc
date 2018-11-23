//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

// TO DO:
// -evalueren
// -differentieren
// -interface
// -verslag
// -DOT
// -doubles ? verwijderen


#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <istream>
#include "token.h"
#include "node.h"
#include "tree.h"

Node* root;

//Voor DOTfunctie.
int a, b, c;
//bool isBinaryOperator() const;

int main() {
a = 0;
b = 0;
c = 0;

Tree S;

S.MakeTree("/ b 0", root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;
//S.DOT(root, a, b, c);
S.TreeSimplify(root);
S.PreOrder(root); std::cout << std::endl;
S.InOrder(root); std::cout << std::endl;


  return 0;
}
