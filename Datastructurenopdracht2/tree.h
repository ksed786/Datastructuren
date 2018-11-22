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
    void Dot();
    void TreeSimplify(Node *root);



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
    InOrder(root->left);

  if(root->token->type == Token::PLUS || Token::MIN ||
                          Token::MULT || Token::DIV || Token::VAR)
      std::cout << root->token->variable << ' ';
  if (root->token->type == Token::NUM)
      std::cout << root->token->number << ' ';

  if (root->right != NULL)
    InOrder(root->right);

}



void Tree::PreOrder (Node *root){

  if(root->token->type == Token::PLUS || Token::MIN ||
                          Token::MULT || Token::DIV || Token::VAR)
    std::cout << root->token->variable << ' ';
  if (root->token->type == Token::NUM)
    std::cout << root->token->number << ' ';

  if (root->left != NULL)
    PreOrder(root->left);
  if (root->right != NULL)
    PreOrder(root->right);


}

void Tree::TreeSimplify (Node *root) {
  if (root->left->token->arity() == 0 && root->right->token->arity() == 0){
    std::cout << "bla0" << '\n';
    root->Simplify();
    root->left = nullptr;
    root->right= nullptr;
  }
  if (root->left->token->arity() != 0) {
    std::cout << "bla1" << '\n';
    TreeSimplify(root->left);
  }
  if (root->right->token->arity() != 0) {
    std::cout << "bla2" << '\n';
    TreeSimplify(root->right);
  }
  if (root->left->token->arity() == 0 && root->right->token->arity() == 0){
    std::cout << "bla0" << '\n';
    root->Simplify();
    root->left = nullptr;
    root->right= nullptr;
  }

}


#endif
