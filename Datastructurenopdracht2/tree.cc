//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

#include "tree.h"

void Tree::MakeTree (std::string invoer, Node *&root){
    std::string deel;
    int nodenumber = 1;
    std::istringstream stream(invoer);
    stream >> deel;
    root = new Node(deel, nodenumber);
    while (stream >> deel) {
      nodenumber++;
      root->AddNode(deel, nodenumber);
    }

}

void Tree::InOrder (Node *root){
  if (root->left != NULL)
    std::cout << "(";

  if (root->left != NULL)
    InOrder(root->left);

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

  if (root->right != NULL) {
    InOrder(root->right);

    std::cout << ")" ;
  }
  if (root->left != NULL && root->right == NULL)
    std::cout << ")" ;

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
  if (root->token->arity() == 2)
    root->Simplify();
  else if (root->token->arity() == 1)
    root->Simplify();
}

void Tree::TreeDifferentiate(Node *root, char x) {
  root->Differentiate(x);
}

void Tree::DOT (std::ofstream &myfile, Node *root , int &b) {

    if (b==1){
      if (root->token->type == Token::NUM){
        myfile << "  " << root->count << " [label=";
        myfile << root->token->number;
      }
      else {
      myfile << "  " << root->count << " [label=" << '\"';
      if(root->token->type == Token::PLUS || Token::MIN ||
                              Token::MULT || Token::DIV || Token::VAR)
          myfile << root->token->variable;
      if(root->token->type == Token::SIN)
        myfile << "sin";
      if(root->token->type == Token::COS)
        myfile << "cos";
        myfile << '\"';
    }
      myfile << "]" << std::endl;;
      b++;

  }

  if (root->left != nullptr) {
    if (root->left->token->type == Token::NUM){
      myfile << "  " << root->left->count << " [label=";
      myfile << root->left->token->number;
    }
    else {
      myfile << "  " << root->left->count << " [label=" << '\"';
      if(root->left->token->type == Token::PLUS || Token::MIN ||
                              Token::MULT || Token::DIV || Token::VAR)
          myfile << root->left->token->variable;
      if(root->left->token->type == Token::SIN)
        myfile << "sin";
      if(root->left->token->type == Token::COS)
        myfile << "cos";
        myfile << '\"';
    }
      myfile << "]" << std::endl;
    myfile << root->count << "->" << root->left->count << std::endl;
    DOT(myfile, root->left, b);
  }

  if (root->right != nullptr) {
    if (root->right->token->type == Token::NUM){
      myfile << "  " << root->right->count << " [label=";
      myfile << root->right->token->number;
    }
    else {
      myfile << "  " << root->right->count << " [label=" << '\"';
    if(root->right->token->type == Token::PLUS || Token::MIN ||
                            Token::MULT || Token::DIV || Token::VAR)
        myfile << root->right->token->variable;
    if(root->right->token->type == Token::SIN)
      myfile << "sin";
    if(root->right->token->type == Token::COS)
      myfile << "cos";
    myfile << '\"';
  }
    myfile << "]" << std::endl;
    myfile << root->count << "->" << root->right->count << std::endl;
    DOT(myfile, root->right, b);
  }
}

void Tree::Evalueren (Node *&root, int x) {
  if(root->token->variable == 'x'){
    root->token->type = Token::NUM;
    root->token->number = x;
  }
  if (root->left != nullptr)
    Evalueren(root->left, x);
  if (root->right != nullptr)
    Evalueren(root->right, x);
}

void Tree::NodeNummerGoedZetten (Node *&root, int a) {
  root->count = a;
  if (root->left != nullptr){
    a++;
    NodeNummerGoedZetten(root->left, a);
  }
  if (root->right != nullptr){
    a++;
    NodeNummerGoedZetten(root->right, a);
  }

}

void Tree::Maakboomleeg(Node *&root){
  if (root->left->left != nullptr)
    Maakboomleeg(root->left);
  if (root->right->left != nullptr)
    Maakboomleeg(root->right);
  if (root->left->left == nullptr && root->right->left == nullptr){
    root->left->token = nullptr;
    root->left = nullptr;
    root->right->token = nullptr;
    root->right = nullptr;
    root->token = nullptr;
    root = nullptr;
  }
}
