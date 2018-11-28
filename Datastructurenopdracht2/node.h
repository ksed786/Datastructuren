//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

#ifndef node_h
#define node_h

#include "token.h"
#include <iostream>
#include <cmath>

//klasse voor knoop
class Node {
public:

  Node(std::string woord, int nodenumber);
  void AddNode(std::string woord , int nodenumber);
  bool IsComplete();
  Node *CopySubTree();
  void Simplify();
  void Differentiate(char x);


  Token* token;
  Node* left;
  Node* right;
  int count;

};

//constructor
Node::Node(std::string woord, int nodenumber) {
  token = new Token(woord);
  left = nullptr;
  right = nullptr;
  count = nodenumber;
}

//voeg node toe. Deze functie wordt aangeroepen door MakeTree.
void Node::AddNode(std::string woord , int nodenumber) {
    int arity = token->arity();

    if (arity == 2) {
      if (left == nullptr) {
        left = new Node(woord ,nodenumber);
      }
      else if (!left->IsComplete()) {
        left->AddNode(woord, nodenumber);
      }
      else if (right == nullptr) {
        right = new Node(woord, nodenumber);
      }
      else if (!right->IsComplete()) {
        right->AddNode(woord , nodenumber);
      }
    }
    if (arity == 1) {
      if (left == nullptr) {
        left = new Node(woord, nodenumber);
      }
      else if (!left->IsComplete()) {
        left->AddNode(woord , nodenumber);
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

//kopieert subbomen voor differentieren.
Node *Node::CopySubTree(){
  //std::cout << "Ingang copyfunctie" << '\n';
  std::stringstream ss;
  std::string str;
  Node* copy;
  int iets;
  if (token->type == Token::NUM) {
  //  std::cout << "ingang getal" << '\n';
    ss << token->number;
    ss >> str;
    copy = new Node(str, iets);
  }
  else {
    //std::cout << "ingang + of x" << '\n';
    ss << token->variable;
    ss >> str;
    copy = new Node(str, iets);
  }
  if (left != nullptr)
    copy->left = left->CopySubTree();
  if (right != nullptr)
    copy->right = right->CopySubTree();
  return copy;
}

//versimpelt expressies
//uitzondering: 0 - x versimpelt niet naar -x
void Node::Simplify() {
  if(token->arity() == 2) {
    if (left->token->type == Token::NUM && right->token->type == Token::NUM) {               // dit moet je ff herzien.
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
    else if (left->token->type == Token::VAR && right->token->type == Token::VAR) {
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
  else if(token->arity() == 1) {                 //dit werkt nu nooit!?
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

//differentieert knoop.
void Node::Differentiate(char x) {
  int iets;
  //constante
  if (token->type == Token::NUM)
    token->number = 0;
  //variable x == x
  else if (token->type == Token::VAR && token->variable == x) {
    token->type = Token::NUM;
    token->number = 1;
  }
  //variable y != x
  else if (token->type == Token::VAR && token->variable != x) {
    token->type = Token::NUM;
    token->number = 0;
  }
  //macht met constante
  else if (token->type == Token::EXP && right->token->type == Token::NUM) {
    if (left->token->type == Token::VAR) {
      Node *temp = CopySubTree();
      Node *temp2 = right->CopySubTree();
      int c = right->token->number;
      token->type = Token::MULT;
      token->variable = '*';
      right = temp;
      left = temp2;
      right->right->token->number = c-1;
    }
    //kettingregel bij macht met constante
    else {
      Node *temp4 = left->CopySubTree();
      Node *temp = CopySubTree();
      Node *temp2 = right->CopySubTree();
      int c = right->token->number;
      token->type = Token::MULT;
      token->variable = '*';
      right = temp;
      left = temp2;
      right->right->token->number = c-1;
      Node *temp3 = CopySubTree();
      left = temp3;
      right = temp4;
      right->Differentiate(x);
    }
  }

  //cos(x)
  if (token->type == Token::COS) {
    if (left->token->type == Token::VAR) {
      Node *temp = left->CopySubTree();
      token->type = Token::MULT;
      token->variable = '*';
      right = new Node("sin", iets);
      right->left = temp;
      left->token->type = Token::NUM;
      left->token->number = -1;
      left->left = nullptr;
      left->right =nullptr;
    }
    //kettingregel met cos(E)
    else {
      Node *temp2 = left->CopySubTree();
      Node *temp = left->CopySubTree();
      token->type = Token::MULT;
      token->variable = '*';
      right = new Node("sin", iets);
      right->token->type = Token::SIN;
      right->left = temp;
      left->token->type = Token::NUM;
      left->token->number = -1;
      left->left = nullptr;
      left->right =nullptr;
      Node *temp3 = CopySubTree();
      left = temp3;
      right = temp2;
      right->Differentiate(x);
    }
  }

  //sin(x)
  else if (token->type == Token::SIN) {
    if (left->token->type == Token::VAR)
      token->type = Token::COS;
    //kettingregel met sin(E)
    else {
      Node *temp = CopySubTree();
      Node *temp2 = left->CopySubTree();
      left = temp;
      left->token->type = Token::COS;
      token->type = Token::MULT;
      token->variable = '*';
      right = temp2;
      right->Differentiate(x);
    }
  }

  //product regel
  else if (token->type == Token::MULT) {
    Node *temp = CopySubTree();
    Node *temp2 = CopySubTree();
    right = temp;
    left = temp2;
    token->type = Token::PLUS;
    token->variable = '+';
    left->left->Differentiate(x);
    right->right->Differentiate(x);
  }

  //quotient regel
  else if (token->type == Token::DIV) {
    Node *temp = CopySubTree();
    Node *temp2 = CopySubTree();
    Node *temp3 = right->CopySubTree();
    left = new Node("-", iets);
    left->left = temp;
    left->right = temp2;
    left->left->token->type = Token::MULT;
    left->left->token->variable = '*';
    left->right->token->type = Token::MULT;
    left->right->token->variable = '*';
    right = new Node("^", iets);
    right->left = temp3;
    right->right = new Node("2", iets);
    left->left->left->Differentiate(x);
    left->right->right->Differentiate(x);
  }

}



#endif
