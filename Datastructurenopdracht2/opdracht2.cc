//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

#include <iostream>
#include <string>
#include <sstream>
#include <istream>

//#include <stack>

struct Token {
        enum {
PLUS, MINUS, NUMBER, VARIABLE } type;
        union {
            char variable;
            double number;
        };
};

struct Node {
  char expressie;
  Node* left;
  Node* right;

};

/*
bool isBinaryOperator() const;


void PreOrder (node *root){

  cout << root->data << ;
  if (root->left != NULL)
    PreOrder(root->left);
  if (root->right != NULL)
    PreOrder(root->right);

}*/

int main() {


  std::string invoer;
  std::cin >> invoer;

  //h is een hulp character. De waarde van h moet de waarde van de vorige "moeder node" zijn.
  char h = ' '

  //hulp pointer
  Node* wijzer = new Node;

  //hij moet dus nu de boom gaan opbouwen
  for (int i=0; i < invoer.length();i++) {

    // als invoer.at een spatie is niks doen.
    if (invoer.at(i) != ' ') {
      Node* vakje = new Node;
      vakje->expressie = invoer.at(i);

      // als hier true uit komt heb je dus een getal te pakken.
      if (invoer.at(i) != '*' || invoer.at(i) != '/' ||
          invoer.at(i) != '+' || invoer.at(i) != '-' ||
          invoer.at(i) != '^') {

        // Hier moet een functie aangeroepen worden die de pointer links of rechts van de moeder node (een operator)
        // naar dit vakje wijst. In de eerste instatie moet je dus de linker hebben. Je moet rechts doen als moeder->links != 0.
        // Deze functie heb ik nog niet gemaakt.

      }//if

      //zorgt dat h veranderd en volgende iteratie gebruikt kan worden.
      h = invoer.at(i);

    }//if

  }//for

  std::cout << std::endl;

  //std::stack<char> first;
  /*for (int i=0; i < invoer.length();i++){

    first.push(invoer.at(i));
    if (first.top() == '(')
      first.pop();

    else if (first.top() == ')') {
      first.pop();
      Node* vakje = new Node;
      vakje->expressie = first.top();
      std::cout << vakje->expressie << std::endl;
    }

  }*/
  /*Node* vakje = new Node;
  vakje->expressie = first.top();
  std::cout << vakje->expressie << std::endl;*/






  return 0;
}
