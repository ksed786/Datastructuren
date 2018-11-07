//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    07-11-2018

#include <iostream>
#include <string>
//#include "stlstack2.h"
#include <stack>

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
//blablab
int main() {

  std::string invoer;
  std::cin >> invoer;


  std::stack<char> first;


  for (int i=0; i < invoer.length();i++){

    first.push(invoer.at(i));
    if (first.top() == '(')
      first.pop();

    else if (first.top() == ')') {
      first.pop();
      Node* vakje = new Node;
      vakje->expressie = first.top();
      std::cout << vakje->expressie << std::endl;
    }

  }







  return 0;
}
