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
    //maakt een boom.
    void MakeTree(std::string invoer, Node *&root);
    //print in pre-orde. wordt niet gebruikt bij de interface,
    //maar is vooral gebruikt het checken van ons programma.
    void PreOrder(Node *root);
    //print in in-orde.
    void InOrder(Node *root);
    //schrijft een file uit met DOT notatie van de boom.
    void DOT(std::ofstream &myfile, Node *root , int &b);
    //versimpelt the boom.
    void TreeSimplify(Node *root);
    //differentieerd de boom.
    void TreeDifferentiate(Node *root, char x);
    //vult een getal in voor de variable x.
    void Evalueren(Node *&root, int x);
    //zet de nummers van de node goed indien de boom is veranderd.
    void NodeNummerGoedZetten(Node *&root, int b);
    //maakt de boom leeg.
    void Maakboomleeg(Node *&root);

    int a, b;
    char name;
}; // Tree

#endif
