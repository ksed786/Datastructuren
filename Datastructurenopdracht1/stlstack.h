//Auteurs:  Olivier Koster (s1826182)
//          Kousar Sedigi  (s1461907)
//Datum:    17-10-2018

#ifndef stlstack_h
#define stlstack_h

#include <stack>


template <typename T>
class Stack{

    std::stack<T> first;

  public:

    void create(); // maak een lege stapel
    bool isEmpty(); // bepaal of de stapel leeg is
    void clear(); // maak de stapel leeg
    bool push(T newItem); // voeg een newItem toe op de top van de stapel, en geef terug of de opdracht gelukt is
    bool pop(); // verwijder het bovenste element van de stapel, en geef terug of de opdracht gelukt is
    bool top(T &topItem); // geef het bovenste stapelelement, zonder dit te verwijderen, en geef terug of de opdracht gelukt is

  private:

};

template <typename T>
void Stack<T>::create() {

}

template <typename T>
bool Stack<T>::isEmpty() {
    if(first.empty()){


        return true;
    }
    else return false;

}//isEmpty


template <typename T>
bool Stack<T>::push(T newItem) {
    first.push(newItem);
    if (first.top() == newItem){

        return true;
    }
    else return false;

}//push

template <typename T>
bool Stack<T>::pop(){
    int size = first.size();
    first.pop();
    if(first.size() == size-1){
        return true;
    }
    else return false;

}//pop

template <typename T>
void Stack<T>::clear() {
    while (first.size() != 0){
        first.pop();

    }

}//clear


template <typename T>
bool Stack<T>::top(T &topItem) {
    topItem = first.top();
    if (topItem == first.top()){
        return true;
    }
    else return false;


}//top

#endif
