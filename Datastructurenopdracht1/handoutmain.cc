//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    17-10-2018


#include <iostream>

#include "array.h"
#include "linkedlist.h"
#include "stlstack.h"
#include "stlvector.h"
#include "backspace.h"
#include <string>


int main(int, char* [])
{
    std::string invoer;
    std::cin >> invoer;

    Array <char> A;
    A.create();
    LinkedList <char> L;
    L.create();
    Stack <char> S;
    S.create();
    Vector <char> V;
    V.create();

    std::cout << std::endl << std::endl;
    std::cout << "Array Stack:  ";
    backspace<Array<char> >(invoer);
    std::cout << "Linked List Stack:  ";
    backspace<LinkedList<char> >(invoer);
    std::cout << "STL Vector Stack:   ";
    backspace<Vector<char> >(invoer);
    std::cout << "STL Stack Stack:    ";
    backspace<Stack<char> >(invoer);
    std::cout << std::endl;
    std::cout << "de stacks zijn achterwaarts afgedrukt omdat deze uiteraard LIFO zijn opgebouwd :)"
              << std::endl << std::endl;


    return 0;
} // main
