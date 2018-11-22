#ifndef tree_h
#define tree_h

#include "node.h"
#include "token.h"
#include <iostream>


class Tree {
  public:
    void MakeTree(std::string invoer, Node *&root);
    void PreOrder(Node *root);
    void InOrder(Node *root);
    void DOT(Node *root, int &a, int &b, int &c);
    void TreeSimplify(Node *root);
    //int NumberOfNodes(Node *root, int &numberofnodes);

    int a, b;
    char name;
};

void Tree::MakeTree (std::string invoer, Node *&root){
    std::string deel;

    std::istringstream stream(invoer);
    stream >> deel;
      //std::cout << deel << std::endl;

    root = new Node(deel);
    while (stream >> deel) {
      //std::cout << deel << std::endl;
      root->AddNode(deel);
    }

}

void Tree::InOrder (Node *root){


  if (root->left != NULL)
    InOrder(root->left);;

  if(root->token->type == Token::PLUS || Token::MIN ||
                          Token::MULT || Token::DIV || Token::VAR)
      std::cout << ' ' << root->token->variable;
  if(root->token->type == Token::SIN)
      std::cout << "sin";
  if(root->token->type == Token::COS)
      std::cout << "cos";
  if (root->token->type == Token::NUM)
      std::cout << root->token->number;

  if (root->right != NULL)
    InOrder(root->right);

}



void Tree::PreOrder (Node *root){

  if(root->token->type == Token::PLUS || Token::MIN ||
                          Token::MULT || Token::DIV || Token::VAR)
    std::cout << ' ' << root->token->variable;
  if (root->token->type == Token::NUM)
    std::cout << root->token->number;
  if(root->token->type == Token::SIN)
    std::cout << "sin";
  if(root->token->type == Token::COS)
    std::cout << "cos";
  if (root->left != NULL)
    PreOrder(root->left);
  if (root->right != NULL)
    PreOrder(root->right);


}

void Tree::TreeSimplify (Node *root) {
  if (root->left != nullptr) {
    TreeSimplify(root->left);
  }
  if (root->right != nullptr) {
    TreeSimplify(root->right);
  }
  if (root->token->arity() == 2) {
    if (root->left->token->type == Token::NUM && root->right->token->type == Token::NUM) {
      root->Simplify();
      root->left = nullptr;
      root->right = nullptr;
    }
  }
  else if (root->token->arity() == 1) {
    if (root->left->token->type == Token::NUM && root->right->token->type == Token::NUM) {
      root->Simplify();
      root->left = nullptr;
    }
  }

}

//commentaar
void Tree::DOT (Node *root, int &a, int &b, int &c) {
    //Diagraph een naam geven (hoofletter) en het begin van de sequence.
    if (a == 1 && b == 2) {
      std::cout<< "Insert letter: diagraph name" << std::endl;
      std::cin >> name;
      std::cout << std::endl << std::endl << std::endl << "diagraph "
                << name << " {" << std::endl;
    }

    //printnode
    std::cout << "  " << c << " [label=" << '"';
      if(root->token->type == Token::PLUS || Token::MIN ||
                              Token::MULT || Token::DIV || Token::VAR)
          std::cout << root->token->variable;
      if (root->token->type == Token::NUM)
          std::cout << root->token->number;
      if(root->token->type == Token::SIN)
        std::cout << "sin";
      if(root->token->type == Token::COS)
        std::cout << "cos";
      std::cout << '"' << "]" << std::endl;

     // gaat linker node in.
      if (root->left != nullptr) {
        c++;
        a++;
        b++;
        DOT(root->left, a, b, c);
      }

      //gaat rechter node in.
      if (root->right != nullptr) {
        c++;
        b++;
        DOT(root->right, a, b, c);
      }

      //printconnectie
      if (root->left == nullptr) {
        a--;
        b--;
        std::cout << "  " << a << "->" << b << std::endl;
        a++;
        b++;

      }

  //std::cout << b << c << '\n';
  //if () {
  //  std::cout << "}" << std::endl;
  //  std::cout << std::endl << std::endl << std::endl << std::endl;
//  }
}




#endif
