//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

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

int a, b, nieuwwaarde;
char x;

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
    //expressie invoeren
    if (deel == "exp"){
      if (root != nullptr){
        expressie = " ";
      }
      while (stream >> deel) {
        expressie += " ";
        expressie += deel;
      }
      S.MakeTree(expressie, root);
    }
    //DOT printen naar .dot-file
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
    //in-orde printen
    else if (deel == "print"){
      S.InOrder(root);
      std::cout <<  std::endl;
    }
    //evalueren
    else if (deel == "eval"){
      stream >> deel;
      std::stringstream(deel) >> nieuwwaarde;
      S.Evalueren(root, nieuwwaarde);
    }
    //differentieren
    else if (deel == "diff"){
      S.TreeDifferentiate(root, x);
      S.NodeNummerGoedZetten(root, a);
    }
    //vereenvoudigen
    else if (deel == "simp"){
      S.TreeSimplify(root);
      int a = 1;
      S.NodeNummerGoedZetten(root, a);
    }
    //beeindigen
  } while (deel != "end");





  return 0;
}
