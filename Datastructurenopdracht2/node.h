#ifndef node_h
#define node_h

#include "token.h"
#include <iostream>
#include <cmath>

//classe van Node
class Node {
public:

  Node(std::string woord);
  void AddNode(std::string woord);
  bool IsComplete();
  void PrintNode();
  //bool Connection(int &a, int &b);
  void Simplify();
  void Differentiate(char x);


  Token* token;
  Node* left;
  Node* right;
  //int i;  nog niet gebruikt

};

//constructor
Node::Node(std::string woord) {
  token = new Token(woord);
  left = nullptr;
  right = nullptr;
}

//voeg node toe. Deze functie wordt aangeroepen door MakeTree.
void Node::AddNode(std::string woord) {
    int arity = token->arity();

    if (arity == 2) {
      if (left == nullptr) {
        left = new Node(woord);
      }
      else if (!left->IsComplete()) {
        left->AddNode(woord);
      }
      else if (right == nullptr) {
        right = new Node(woord);
      }
      else if (!right->IsComplete()) {
        right->AddNode(woord);
      }
    }
    if (arity == 1) {
      if (left == nullptr) {
        left = new Node(woord);
      }
      else if (!left->IsComplete()) {
        left->AddNode(woord);
      }
    }

    else if (arity == 0){
      std::cout << "Error!" << std::endl;

    }
}

//Checkt of de boom compleet is.
bool Node::IsComplete() {
  int arity = token->arity();
  if (arity == 0)
    return true;
  if (arity == 2 ) {
    if (left != nullptr && right != nullptr &&
        left->IsComplete() && right->IsComplete())
      return true;
    else return false;
  }
  if (arity == 1){
    if (left != nullptr && left->IsComplete())
      return true;
    else return false;
  }
  else return false;
}

//versimpelt expressies
//uitzondering: 0 - x versimpelt niet naar -x
void Node::Simplify() {
  if (left->token->type == Token::NUM && right->token->type == Token::NUM) {
    if(token->arity() == 2) {
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
        if (b != 0) {
          a = a / b;
          token->type = Token::NUM;
          token->number = a;
        }
        else std::cout << "Error! Mag niet delen door 0!" << '\n';
      }
      else if (token->type == Token::EXP) {
        a = pow(a , b);
        token->type = Token::NUM;
        token->number = a;
      }

      left = nullptr;
      right = nullptr;
    }
    if(token->arity() == 1) {
      double a = left->token->number;
      if (token->type == Token::SIN) {
        a = sin(a);
        token->type = Token::NUM;
        token->number = a;
      }
      else if (token->type == Token::COS) {
        token->type = Token::NUM;
        token->number = cos(a);
      }
      left = nullptr;
    }
  }
  if (left->token->type == Token::VAR && right->token->type == Token::VAR) {
    if (token->type == Token::MIN)
      if (left->token->variable == right->token->variable) {
          token->type = Token::NUM;
          token->number = 0;
          left = nullptr;
          right = nullptr;
      }
    if (token->type == Token::DIV)
      if (left->token->variable == right->token->variable) {
          token->type = Token::NUM;
          token->number = 1;
          left = nullptr;
          right = nullptr;
      }
  }
  else {
    if (token->type == Token::PLUS) {
      if (left->token->type == Token::NUM && left->token->number == 0) {
          token->type = Token::VAR;
          token->variable = right->token->variable;
          left = nullptr;
          right = nullptr;
      }
      else if (right->token->type == Token::NUM && right->token->number == 0) {
          token->type = Token::VAR;
          token->variable = left->token->variable;
          left = nullptr;
          right = nullptr;
      }
    }
    else if (token->type == Token::MIN) {
      if (right->token->type == Token::NUM && right->token->number == 0) {
          token->type = Token::VAR;
          token->variable = left->token->variable;
          left = nullptr;
          right = nullptr;
      }
      //deze plek was gereserveerd voor een mogelijke oplossing voor 0 - x.
      /* else if (right->token->type == Token::NUM && right->token->number == 0) {
          token->type = Token::VAR;
          token->variable = left->token->variable;
          left = nullptr;
          right = nullptr;
      } */
    }
    else if (token->type == Token::MULT) {
      if (left->token->type == Token::NUM && left->token->number == 1) {
          token->type = Token::VAR;
          token->variable = right->token->variable;
          left = nullptr;
          right = nullptr;
      }
      else if (right->token->type == Token::NUM && right->token->number == 1) {
          token->type = Token::VAR;
          token->variable = left->token->variable;
          left = nullptr;
          right = nullptr;
      }
      else if (left->token->type == Token::NUM && left->token->number == 0) {
          token->type = Token::NUM;
          token->number = 0;
          left = nullptr;
          right = nullptr;
      }
      else if (right->token->type == Token::NUM && right->token->number == 0) {
          token->type = Token::NUM;
          token->number = 0;
          left = nullptr;
          right = nullptr;
      }
    }
    else if (token->type == Token::DIV && right->token->type == Token::NUM &&
             right->token->number == 0) {
      std::cout << "Error! Mag niet delen door 0!" << '\n';
    }
    else if (token->type == Token::EXP) {
      if (left->token->type == Token::NUM && left->token->number == 1) {
          token->type = Token::VAR;
          token->variable = right->token->variable;
          left = nullptr;
          right = nullptr;
      }
      else if (right->token->type == Token::NUM && right->token->number == 1) {
          token->type = Token::VAR;
          token->variable = left->token->variable;
          left = nullptr;
          right = nullptr;
      }
      else if (left->token->type == Token::NUM && left->token->number == 0) {
          token->type = Token::NUM;
          token->number = 1;
          left = nullptr;
          right = nullptr;
      }
      else if (right->token->type == Token::NUM && right->token->number == 0) {
          token->type = Token::NUM;
          token->number = 1;
          left = nullptr;
          right = nullptr;
      }
    }
  }
}

//differentieert node.
void Node::Differentiate(char x) {
  //constante
  if (token->type == Token::NUM)
    token->number = 0;
  //variable x == x
  if (token->type == Token::VAR && token->variable == x) {
    token->type = Token::NUM;
    token->number = 1;
  }
  //variable y != x
  if (token->type == Token::VAR && token->variable != x) {
    token->type = Token::NUM;
    token->number = 0;
  }
  //macht met constante
  //cos(x)
  //if (token->type == Token::SIN) {
  //  token->type = Token::COS;
  //}
  //sin(x)
  if (token->type == Token::SIN) {
    token->type = Token::COS;
  }
}



#endif
