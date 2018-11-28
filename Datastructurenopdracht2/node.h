//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    28-11-2018

#ifndef node_h
#define node_h

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

#endif
