//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

// TO DO:
// -evalueren
// -differentieren
// -interface
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
int a, b, c, nieuwewaarde;
char x;
//bool isBinaryOperator() const;

int main() {
//beginDOT
a = 1;
b = 1;
c = 0;

Tree S;
std::cout << "Naar welke variablen differentieren? Voer in:" << '\n';
std::cin >> x;
std::cout << "Wat wordt de nieuwe waarde voor x?" << '\n';
std::cin >> nieuwewaarde;

S.MakeTree("+ 2 4", root);

//S.CopySubTree(root);
//std::cout << "de afgeleide van ' ";
S.PreOrder(root);
std::cout << std::endl;
S.TreeSimplify(root);
std::cout << std::endl;
S.PreOrder(root);
//S.DOT(root, b);

S.Evalueren(root, x, nieuwewaarde);
std::cout << std::endl;
S.PreOrder(root);
std::cout << std::endl;
S.TreeSimplify(root);
std::cout << std::endl;
S.PreOrder(root);

//S.TreeSimplify(root);
//std::cout << " ' is ' ";
//S.PreOrder(root);
std::cout << '\n';
//std::cout << " '" << '\n';
//S.InOrder(root); std::cout << std::endl;



  return 0;
}
