//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <cmath>
#include "token.h"
#include "node.h"
#ifndef tree_h
#define tree_h

//Klasse voor boom
class Tree {
  public:
    void MakeTree(std::string invoer, Node *&root);
    void PreOrder(Node *root);
    void InOrder(Node *root);
    void DOT(std::ofstream &myfile, Node *root , int &b);
    void TreeSimplify(Node *root);
    void TreeDifferentiate(Node *root, char x);
    void Evalueren(Node *&root, int x);
    void NodeNummerGoedZetten(Node *&root, int b);
    void Maakboomleeg(Node *&root);

    int a, b;
    char name;
};

#endif
