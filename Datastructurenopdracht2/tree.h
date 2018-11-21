#ifndef tree_h
#define tree_h

#include "node.h"
#include "token.h"
#include <iostream>


class Tree {
  public:
    void MakeTree(std::string invoer);
    void PreOrder();
    void Dot();
  private:
    Node* root;

};

void Tree::MakeTree (std::string invoer){
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

void Tree::PreOrder (){

  if(root->token->type == Token::PLUS || Token::MULT)
    std::cout << root->token->variable << '\n';

    if (root->left != NULL)
      PreOrder(root->left);
    if (root->right != NULL)
      PreOrder(root->right);
}

#endif
