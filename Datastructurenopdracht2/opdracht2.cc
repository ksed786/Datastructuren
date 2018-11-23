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
// -onnodige dingetje weghalen
// -commentaar en netheid: switchcases!
// -check feedback op verbeterpunten.
// check? "Goed!"


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
char x;
//bool isBinaryOperator() const;

int main() {
//beginDOT
a = 0;
b = 0;
c = 0;

Tree S;
std::cout << "Naar welke variablen differentieren? Voer in:" << '\n';
std::cin >> x;

S.MakeTree("5", root);
S.CopySubTree(root);
std::cout << "de afgeleide van ' ";
//S.PreOrder(root);
//S.InOrder(root); std::cout << std::endl;
//S.TreeDifferentiate(root, x);
//S.DOT(root, a, b, c);
//S.TreeSimplify(root);
std::cout << " ' is ' ";
//S.PreOrder(root);
std::cout << " '" << '\n';
//S.InOrder(root); std::cout << std::endl;



  return 0;
}
