#ifndef node_h
#define node_h

#include "token.h"
#include <iostream>
#include <cmath>

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
    if (arity == 1) {
      if (left == nullptr) {
        left = new Node(woord);
      }
      else if (!left->iscomplete()) {
        left->AddNode(woord);
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
  if (arity == 1){
    if (left != nullptr && left->iscomplete())
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
    else if (token->type == Token::MIN) {
      a = a - b;
      token->type = Token::NUM;
      token->number = a;
    }
    else if (token->type == Token::MULT) {
      a = a * b;
      token->type = Token::NUM;
      token->number = a;
    }
    else if (token->type == Token::DIV) {
      a = a / b;
      token->type = Token::NUM;
      token->number = a;
    }
    else if (token->type == Token::EXP) {
      a = pow(a , b);
      token->type = Token::NUM;
      token->number = a;
    }
    else if (token->type == Token::SIN) {
      a = sin(a);
      token->type = Token::NUM;
      token->number = a;
    }
    else if (token->type == Token::COS) {
      token->type = Token::NUM;
      token->number = cos(a);
    }

}


/*
void Node::DOT () {
    int counter = 0;
    std::cout << "digraph G {" << std::endl;
    for (int i = 0; i < lenght;i++) {
      std::cout << "  " << counter << "[label=" << PrintNode() << "]" std::endl;    //print(token)
      if (connection(a, b))
        std::cout << a << "->" << b << std::endl;
    }

}*/


#endif
