#ifndef node_h
#define node_h

#include "token.h"
#include <iostream>

class Node {
public:

  Node(std::string woord);
  void AddNode(std::string woord);
  bool iscomplete();
  void PrintNode();
  bool Connection(int &a, int &b);
  void Simplify();


  Token* token;
  Node* left;
  Node* right;

};

Node::Node(std::string woord) {
  token = new Token(woord);
  left = nullptr;
  right = nullptr;
}

void Node::AddNode(std::string woord) {
    int arity = token->arity();

    if (arity == 2) {
      if (left == nullptr) {
        left = new Node(woord);
      }
      else if (!left->iscomplete()) {
        left->AddNode(woord);
      }
      else if (right == nullptr) {
        right = new Node(woord);
      }
      else if (!right->iscomplete()) {
        right->AddNode(woord);
      }
    }
    else if (arity == 0){
      std::cout << "Error!" << std::endl;

    }
}

bool Node::iscomplete() {
  int arity = token->arity();
  if (arity == 0)
    return true;
  if (arity == 2 ) {
    if (left != nullptr && right != nullptr &&
        left->iscomplete() && right->iscomplete())
      return true;
    else return false;
  }
  else return false;
}

void Node::Simplify() {
    double a = left->token->number;
    double b = right->token->number;
    if (token->type == Token::PLUS) {
      a = a + b;
      token->type = Token::NUM;
      token->number = a;
    }
}


#endif
