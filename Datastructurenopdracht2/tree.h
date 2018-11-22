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
    void DOT(Node *root, int &a, int &b);
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
  if (root->left != nullptr) {
    TreeSimplify(root->left);
  }
  if (root->right != nullptr) {
    TreeSimplify(root->right);
  }
  if (root->token->type == Token::PLUS) {
    root->Simplify();
    root->left = nullptr;
    root->right = nullptr;
  }
}

//commentaar
void Tree::DOT (Node *root, int &a, int &b) {
    //Diagraph een naam geven (hoofletter) en het begin van de sequence.
    if (a == 1 && b == 2) {
      std::cout<< "Insert letter: diagraph name" << std::endl;
      std::cin >> name;
      std::cout << std::endl << std::endl << std::endl << "diagraph "
                << name << " {" << std::endl;
    }
    std::cout << "  " << a << " [label= ";

      //printtoken.
      if(root->token->type == Token::PLUS || Token::MIN ||
                              Token::MULT || Token::DIV || Token::VAR)
          std::cout << root->token->variable << ' ';
      if (root->token->type == Token::NUM)
          std::cout << root->token->number << ' ';
      std::cout << "]" << std::endl;
      if (root->left != nullptr)
        DOT(root->left, b, a);


      std::cout << "  " << a << "->" << b << std::endl;





  std::cout << "}" << std::endl;
  std::cout << std::endl << std::endl << std::endl << std::endl;
}




#endif
