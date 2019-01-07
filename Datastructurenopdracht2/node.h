//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

#include "token.h"
#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <cmath>

#ifndef node_h
#define node_h

//klasse voor knoop
class Node {
public:

  //constructor
  Node(std::string woord, int nodenumber);
  //destructor
  Node::~Node()
  //voeg node toe. Deze functie wordt aangeroepen door MakeTree.
  void AddNode(std::string woord , int nodenumber);
  //Checkt of de boom compleet is.
  bool IsComplete();
  //kopieert subbomen voor differentieren.
  Node *CopySubTree();
  //versimpelt expressies
//uitzondering: 0 - x versimpelt niet naar -x
  void Simplify();
  //differentieert knoop.
  void Differentiate(char x);


  Token* token;
  Node* left;
  Node* right;
  int count;

};

#endif
