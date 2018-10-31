//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    17-10-2018

#ifndef Backspace_h
#define Backspace_h

#include <iostream>

template <typename T>
void backspace(std::string invoer) {

  T stapel;
  stapel.create();

  for (int i=0; i < invoer.length(); i++) {
    if (invoer.at(i) == '*')
      stapel.pop();
    else
      stapel.push(invoer.at(i));
  }//for

  while (!stapel.isEmpty()) {
    char a;
    stapel.top(a);
    std::cout << a;
    stapel.pop();
  }//while
  std::cout << std::endl;

}//backspace
#endif
