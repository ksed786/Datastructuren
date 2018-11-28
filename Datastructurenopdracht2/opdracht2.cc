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
#include <fstream>
#include "token.h"
#include "node.h"
#include "tree.h"


Node* root;
//Voor DOTfunctie.
int a, b, nieuwwaarde;
char x;
//bool isBinaryOperator() const;

int main() {
  Tree S;
  std::string invoer;
  std::string deel;
  std::string expressie;
  do {
  std::getline (std::cin,invoer);
  std::istringstream stream(invoer);
  stream >> deel;
    if (deel == "exp"){
      if (root != nullptr){
        S.Maakboomleeg(root);
        expressie = " ";
      }
      while (stream >> deel) {
        expressie += " ";
        expressie += deel;
      }
      S.MakeTree(expressie, root);
    }
    else if (deel == "dot"){
      int b = 1;
      stream >> deel;
      std::ofstream myfile (deel);
      if (myfile.is_open()) {
        myfile << "digraph G {\n";
        S.DOT(myfile, root, b);
        myfile << "}";
        myfile.close();
      }
    }
    else if (deel == "print"){
      S.InOrder(root);
      std::cout <<  std::endl;
    }
    else if (deel == "eval"){
      stream >> deel;
      std::stringstream(deel) >> nieuwwaarde;
      S.Evalueren(root, nieuwwaarde);
    }
    else if (deel == "diff"){
      S.TreeDifferentiate(root, x);
    }
    else if (deel == "simp"){
      S.TreeSimplify(root);
      int a = 1;
      S.NodeNummerGoedZetten(root, a);
    }

  } while (deel != "end");





  return 0;
}
