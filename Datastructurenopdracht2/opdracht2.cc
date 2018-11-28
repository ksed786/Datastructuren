//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

// TO DO:
// -doubles ? verwijderen
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

<<<<<<< HEAD

Node* root;
//Voor DOTfunctie.
int a, b, nieuwwaarde;
char x;
//bool isBinaryOperator() const;
=======

Node* root;

int a, b, nieuwwaarde;
char x;
>>>>>>> Olivier

//main interface
int main() {
  Tree S;
  std::string invoer;
  std::string deel;
  std::string expressie;
  do {
  std::getline (std::cin,invoer);
  std::istringstream stream(invoer);
  stream >> deel;
<<<<<<< HEAD
=======
    //expressie invoeren
>>>>>>> Olivier
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
<<<<<<< HEAD
=======
    //DOT printen naar .dot-file
>>>>>>> Olivier
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
<<<<<<< HEAD
=======
    //in-orde printen
>>>>>>> Olivier
    else if (deel == "print"){
      S.InOrder(root);
      std::cout <<  std::endl;
    }
<<<<<<< HEAD
=======
    //evalueren
>>>>>>> Olivier
    else if (deel == "eval"){
      stream >> deel;
      std::stringstream(deel) >> nieuwwaarde;
      S.Evalueren(root, nieuwwaarde);
    }
<<<<<<< HEAD
    else if (deel == "diff"){
      S.TreeDifferentiate(root, x);
    }
=======
    //differentieren
    else if (deel == "diff"){
      S.TreeDifferentiate(root, x);
    }
    //vereenvoudigen
>>>>>>> Olivier
    else if (deel == "simp"){
      S.TreeSimplify(root);
      int a = 1;
      S.NodeNummerGoedZetten(root, a);
    }
<<<<<<< HEAD

=======
    //beeindigen
>>>>>>> Olivier
  } while (deel != "end");





  return 0;
}
