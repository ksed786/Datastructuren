//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

// TO DO:
// -differentieren
// -doubles ? verwijderen
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


int a, b, c, nieuwwaarde;
char x;

//main interface
int main() {
//beginDOT
a = 1;
b = 1;
c = 0;

Tree S;

std::cout << "Naar welke variablen differentieren? Voer in:" << '\n';
std::cin >> x;

//voor evalueren
//std::cout << "Wat wordt de nieuwe waarde voor x?" << '\n';
//std::cin >> nieuwwaarde;

S.MakeTree("cos * x y", root);
//std::cout << "de afgeleide van ' ";

//S.DOT(root, b);

//S.Evalueren(root, nieuwwaarde);
std::cout << std::endl;
//S.TreeSimplify(root);
std::cout << std::endl;
S.PreOrder(root);
std::cout << std::endl;
S.TreeDifferentiate(root, x);
//S.TreeSimplify(root);
//std::cout << " ' is ' ";
S.PreOrder(root);
std::cout << '\n';
//std::cout << " '" << '\n';
//S.InOrder(root); std::cout << std::endl;



  return 0;
}
