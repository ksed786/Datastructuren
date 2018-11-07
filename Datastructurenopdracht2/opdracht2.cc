//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

#include <string>
#include <sstream>
#include <istream>
#include "token.h"
#include "node.h"
//#include "tree.h"
//#include <stack>

void MakeTree (std::string invoer){
    std::string deel;

    std::istringstream stream(invoer);
    stream >> deel;
    Node* root = new Node(deel);
    while (stream >> deel) {
      root->AddNode(deel);
    }

}



int main() {

MakeTree("+ 5 * 6 7");

  return 0;
}
