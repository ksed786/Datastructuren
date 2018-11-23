#ifndef tree_h
#define tree_h

#include "node.h"
#include "token.h"
#include <iostream>
#include <string>


class Tree {
  public:
    void MakeTree(std::string invoer, Node *&root);
    void PreOrder(Node *root);
    void InOrder(Node *root);
    void DOT(Node *root, int &a, int &b, int &c);
    void TreeSimplify(Node *root);
    void TreeDifferentiate(Node *root, char x);
    void CopySubTree(Node *root);
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

void Tree::CopySubTree(Node *root){
  std::stringstream ss;
  std::string str;
  Node* copy;
  if (root->token->type == Token::NUM) {
    ss << root->token->number;
    ss >> str;
    copy = new Node(str);
  }
  else {
    ss << root->token->variable;
    ss >> str;
    copy = new Node(str);
  }
  if (root->left != nullptr)
    CopySubTree(Copy->left)
  if (root->right != nullptr)
    CopySubTree(Copy->right)
}

void Tree::InOrder (Node *root){


  if (root->left != NULL)
    InOrder(root->left);;

  if(root->token->type == Token::PLUS || Token::MIN ||
                          Token::MULT || Token::DIV ||
                          Token::VAR)
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
                          Token::MULT || Token::DIV ||
                          Token::VAR)
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
    if ((root->left->token->type == Token::PLUS &&
         root->left->left->token->type == Token::NUM &&
         root->left->left->token->number == 0) ||
        (root->left->token->type == Token::MULT &&
         root->left->left->token->type == Token::NUM &&
         root->left->left->token->number == 1)) {
      root->left = root->left->right;
    }
    if ((root->left->token->type == Token::PLUS &&
         root->left->right->token->type == Token::NUM &&
         root->left->right->token->number == 0) ||
        (root->left->token->type == Token::MULT &&
         root->left->right->token->type == Token::NUM &&
         root->left->right->token->number == 1) ||
        (root->left->token->type == Token::EXP &&
         root->left->right->token->type == Token::NUM &&
         root->left->right->token->number == 1)) {
      root->left = root->left->left;
    }
    TreeSimplify(root->left);
  }
  if (root->right != nullptr) {
    if ((root->right->token->type == Token::PLUS &&
         root->right->left->token->type == Token::NUM &&
         root->right->left->token->number == 0) ||
        (root->right->token->type == Token::MULT &&
         root->right->left->token->type == Token::NUM &&
         root->right->left->token->number == 1)) {
      root->right = root->right->right;
    }
    if ((root->right->token->type == Token::PLUS &&
         root->right->right->token->type == Token::NUM &&
         root->right->right->token->number == 0) ||
        (root->right->token->type == Token::MULT &&
         root->right->right->token->type == Token::NUM &&
         root->right->right->token->number == 1) ||
        (root->right->token->type == Token::EXP &&
         root->right->right->token->type == Token::NUM &&
         root->right->right->token->number == 1)) {
      root->right = root->right->left;
    }
    TreeSimplify(root->right);
  }
  if (root->token->arity() == 2)          //is dit niet onnodig???
    root->Simplify();
  else if (root->token->arity() == 1)      //********************************
    root->Simplify();
}

//differentieerd de boom. deze functie moet recursief zijn.
void Tree::TreeDifferentiate(Node *root, char x) {
  if (root->left != nullptr)
    TreeDifferentiate(root, x);
  if (root->right != nullptr) {
    TreeDifferentiate(root, x);
    root->Differentiate(x);
  //iets van nieuwe subboom maken met pointer sub? ofmoet dit in NODE?
  //return sub;
  }

}

//commentaar
/*void Tree::DOT (Node *root, int &a, int &b, int &c) {
    //Diagraph een naam geven (hoofletter) en het begin van de sequence.
    if (a == 0 && b == 1) {
      std::cout<< "Insert letter: diagraph name" << std::endl;
      std::cin >> name;
      std::cout << std::endl << std::endl << std::endl << "digraph "
                << name << " {" << std::endl;
    }

    //printnode
    std::cout << "  " << b << " [label=" << '"';
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
      if (!(a == 0 && b == 1)) {
        std::cout << "  " << a << "->" << b << std::endl;
      }

     // gaat linker node in.
      if (root->left != nullptr) {
        a++;
        b++;
        c++;
        DOT(root->left, a, b, c);
        a--;
      }

      //gaat rechter node in.
      if (root->right != nullptr) {
        a++;
        b++;
        DOT(root->right, a, b, c);
        a--;
      }

  //std::cout << b << c << '\n';
  //if () {
  //  std::cout << "}" << std::endl;
  //  std::cout << std::endl << std::endl << std::endl << std::endl;
//  }
}
*/



#endif
